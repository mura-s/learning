package sample

import org.apache.spark.ml.Pipeline
import org.apache.spark.ml.classification.NaiveBayes
import org.apache.spark.ml.feature.HashingTF
import org.apache.spark.sql.SparkSession

/**
  * Ex2
  *
  * 実行方法:
  *   sbt clean package
  *   spark-submit --class sample.BasicNaiveBayes target/scala-2.11/spark-sample_2.11-1.0.jar
  */
object BasicNaiveBayes {

  def main(args: Array[String]) = {
    val spark = SparkSession
      .builder()
      .appName("Basic NaiveBayes")
      .getOrCreate()

    val df = spark.createDataFrame(Seq(
      (1.0, "MLlib is Spark s machine learning library"),
      (0.0, "Mahout is machine learning library"),
      (1.0, "GraphX is a new component in Spark"),
      (0.0, "Mahout uses Hadoop platform"),
      (1.0, "SparkR is a R package"),
      (0.0, "Hadoop is a framework for the distributed processing"),
      (1.0, "Spark SQL is a Spark module"),
      (0.0, "HDFS is a distributed file system")
    ).map(t => (t._1, t._2.split(" ")))).toDF("doc_class", "words")

    val hashingTF = new HashingTF().setInputCol("words").setOutputCol("hashing_tf")

    val naiveBayes = new NaiveBayes().setFeaturesCol("hashing_tf").setLabelCol("doc_class")

    val pipeline = new Pipeline().setStages(Array(hashingTF, naiveBayes))

    val predictionModel = pipeline.fit(df)

    val prediction = predictionModel.transform(df)

    println(prediction.show())

  }

}
