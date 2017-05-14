package sample

import org.apache.spark.ml.Pipeline
import org.apache.spark.ml.linalg.{Vector, Vectors}
import org.apache.spark.ml.classification.LogisticRegression
import org.apache.spark.ml.feature.{HashingTF, Tokenizer}
import org.apache.spark.sql.{Row, SparkSession}

/**
  * Ex4
  *
  * 実行方法:
  *   sbt clean package
  *   spark-submit --class sample.BasicLogisticRegressionPipeline target/scala-2.11/spark-sample_2.11-1.0.jar
  */
object BasicLogisticRegressionPipeline {

  def main(args: Array[String]) = {
    val spark = SparkSession
      .builder()
      .appName("Basic LogisticRegressionPipeline")
      .getOrCreate()

    val training = spark.createDataFrame(Seq(
      (0L, "a b c d e spark", 1.0),
      (1L, "b d", 0.0),
      (2L, "spark f g h", 1.0),
      (3L, "hadoop mapreduce", 0.0)
    )).toDF("id", "text", "label")

    val tokenizer = new Tokenizer()
      .setInputCol("text")
      .setOutputCol("words")

    val hashingTF = new HashingTF()
      .setNumFeatures(1000)
      .setInputCol(tokenizer.getOutputCol)
      .setOutputCol("features")

    val lr = new LogisticRegression()
      .setMaxIter(10)
      .setRegParam(0.001)

    val pipeline = new Pipeline()
      .setStages(Array(tokenizer, hashingTF, lr))

    val model = pipeline.fit(training)

    val test = spark.createDataFrame(Seq(
      (4L, "spark i j k"),
      (5L, "l m n"),
      (6L, "spark hadoop spark"),
      (7L, "apache hadoop")
    )).toDF("id", "text")

    model.transform(test)
      .select("id", "text", "probability", "prediction")
      .collect()
      .foreach { case Row(id: Long, text: String, prob: Vector, prediction: Double) =>
        println(s"($id, $text) --> prob=$prob, prediction=$prediction")
      }

    // workdsやfeaturesを表示してみる
/*    model.transform(test)
      .select("id", "words", "features", "probability", "prediction")
      .show(20, false)*/

    // SparceVectorを表示してみる
/*    val sVec = Vectors.sparse(5, Seq((1, 1.0), (3, 7.0)))
    println(sVec)*/

  }

}
