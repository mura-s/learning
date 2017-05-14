package sample

import org.apache.spark.ml.classification.{BinaryLogisticRegressionSummary, LogisticRegression}
import org.apache.spark.ml.linalg.{Vector, Vectors}
import org.apache.spark.ml.param.ParamMap
import org.apache.spark.sql.{Row, SparkSession}
import org.apache.spark.sql.functions._

/**
  * Ex3
  *
  * 実行方法:
  *   sbt clean package
  *   spark-submit --class sample.BasicLogisticRegression1 target/scala-2.11/spark-sample_2.11-1.0.jar
  */
object BasicLogisticRegression1 {

  // no pipeline
  def main(args: Array[String]) = {
    val spark = SparkSession
      .builder()
      .appName("Basic LogisticRegression1")
      .getOrCreate()

    val training = spark.createDataFrame(Seq(
      (0, Vectors.dense(0.0, 1.1, 0.1), 1.0),
      (1, Vectors.dense(2.0, 1.0, -1.0), 0.0),
      (2, Vectors.dense(2.0, 1.3, 1.0), 0.0),
      (3, Vectors.dense(0.0, 1.2, -0.5), 1.0)
    )).toDF("id", "features", "label")

    val lr = new LogisticRegression()
    println("LR parameters: " + lr.explainParams() + "\n")

    val paramMap = ParamMap()
      .put(lr.maxIter -> 30, lr.regParam -> 0.1, lr.threshold -> 0.55, lr.standardization -> false)

    val paramMap2 = ParamMap(lr.probabilityCol -> "myProbability")
    val paramMapCombined = paramMap ++ paramMap2

    val model2 = lr.fit(training, paramMapCombined)
    println("Model 2 was fit using parameters: " + model2.parent.extractParamMap())

    /*val trainingSummary = model2.summary
    val objectiveHistory = trainingSummary.objectiveHistory
    objectiveHistory.foreach(loss => println(loss))

    val binarySummary = trainingSummary.asInstanceOf[BinaryLogisticRegressionSummary]
    val roc = binarySummary.roc
    roc.show()
    println(s"areaUnderROC: ${binarySummary.areaUnderROC}")

    import spark.implicits._

    val fMeasure = binarySummary.fMeasureByThreshold
    val maxFMeasure = fMeasure.select(max("F-Measure")).head().getDouble(0)
    val bestThreshold = fMeasure.where($"F-Measure" === maxFMeasure)
      .select("threshold").head().getDouble(0)
    println(s"threshold: ${bestThreshold}")*/

    val test = spark.createDataFrame(Seq(
      (0, Vectors.dense(-1.0, 1.5, 1.3)),
      (1, Vectors.dense(3.0, 2.0, -0.1)),
      (2, Vectors.dense(0.0, 2.2, -1.5))
    )).toDF("id", "features")

    model2.transform(test)
      .select("features", "myProbability", "prediction")
      .collect()
      .foreach { case Row(features: Vector, prob: Vector, prediction: Double) =>
        println(s"$features -> prob=$prob, prediction=$prediction")
      }

    println(s"coef: ${model2.coefficients}, intercept: ${model2.intercept}")

  }

}
