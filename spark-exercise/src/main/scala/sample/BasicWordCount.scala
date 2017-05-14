package sample

import org.apache.spark.{SparkConf, SparkContext}

/**
  * Ex1
  *
  * 実行方法:
  *   sbt clean package
  *   spark-submit --class sample.BasicWordCount target/scala-2.11/spark-sample_2.11-1.0.jar
  */
object BasicWordCount {

  def main(args: Array[String]) = {
    val conf = new SparkConf().setAppName("Basic WordCount")
    val sc = new SparkContext(conf)

    val textFile = sc.textFile("/usr/local/Cellar/apache-spark/2.1.0/README.md")
    val words = textFile.flatMap(line => line.split(" "))
    val wordCounts = words.map(word => (word, 1)).reduceByKey((a, b) => a + b)

    wordCounts.saveAsTextFile("./wordcounts")
  }

}
