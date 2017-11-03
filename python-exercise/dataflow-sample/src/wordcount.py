"""A word-counting workflow."""

from __future__ import absolute_import

import re
import argparse
import logging

import apache_beam as beam
from apache_beam.io import ReadFromText
from apache_beam.io import WriteToText
from apache_beam.metrics import Metrics
from apache_beam.metrics.metric import MetricsFilter
from apache_beam.options.pipeline_options import PipelineOptions
from apache_beam.options.pipeline_options import SetupOptions


class WordExtractingDoFn(beam.DoFn):
    """Parse each line of input text into words."""

    def __init__(self):
        super(WordExtractingDoFn, self).__init__()
        self.words_counter = Metrics.counter(self.__class__, 'words')
        self.word_lengths_counter = Metrics.counter(self.__class__, 'word_lengths')
        self.word_lengths_dist = Metrics.distribution(self.__class__, 'word_len_dist')
        self.empty_line_counter = Metrics.counter(self.__class__, 'empty_lines')

    def process(self, element):
        """Returns an iterator over the words of this element."""
        text_line = element.strip()
        if not text_line:
            self.empty_line_counter.inc(1)
        words = re.findall(r'[A-Za-z\']+', text_line)
        for w in words:
            self.words_counter.inc()
            self.word_lengths_counter.inc(len(w))
            self.word_lengths_dist.update(len(w))
        return words


def run(argv=None):
    """Main entry point."""
    parser = argparse.ArgumentParser()
    parser.add_argument('--input',
                        dest='input',
                        default='gs://dataflow-samples/shakespeare/kinglear.txt',
                        help='Input file to process.')
    parser.add_argument('--output',
                        dest='output',
                        required=True,
                        help='Output file to write results to.')
    known_args, pipeline_args = parser.parse_known_args(argv)

    pipeline_options = PipelineOptions(pipeline_args)
    pipeline_options.view_as(SetupOptions).save_main_session = True
    p = beam.Pipeline(options=pipeline_options)

    lines = p | 'read' >> ReadFromText(known_args.input)

    def count_ones(word_ones):
        (word, ones) = word_ones
        return (word, sum(ones))

    counts = (lines
              | 'split' >> (beam.ParDo(WordExtractingDoFn()).with_output_types(unicode))
              | 'pair_with_one' >> beam.Map(lambda x: (x, 1))
              | 'group' >> beam.GroupByKey()
              | 'count' >> beam.Map(count_ones))

    def format_result(word_count):
        (word, count) = word_count
        return '%s: %s' % (word, count)

    output = counts | 'format' >> beam.Map(format_result)
    output | 'write' >> WriteToText(known_args.output)

    result = p.run()
    result.wait_until_finish()

    if (not hasattr(result, 'has_job') or result.has_job):
        empty_line_filter = MetricsFilter().with_name('empty_lines')
        query_result = result.metrics().query(empty_line_filter)
        if query_result['counters']:
            empty_line_counter = query_result['counters'][0]
            logging.info('number of empty lines: %d', empty_line_counter.committed)

        word_lengths_filter = MetricsFilter().with_name('word_len_dist')
        query_result = result.metrics().query(word_lengths_filter)
        if query_result['distributions']:
            word_lengths_dist = query_result['distributions'][0]
            logging.info('average word length: %d', word_lengths_dist.committed.mean)


if __name__ == '__main__':
    logging.getLogger().setLevel(logging.INFO)
    run()
