package sample

import org.apache.spark.ml.{Pipeline, PipelineModel}
import org.apache.spark.ml.linalg.{Vector, Vectors}
import org.apache.spark.ml.classification.{BinaryLogisticRegressionSummary, LogisticRegression, LogisticRegressionModel}
import org.apache.spark.ml.evaluation.{BinaryClassificationEvaluator, BinaryLogLossEvaluator, MulticlassClassificationEvaluator, RegressionEvaluator}
import org.apache.spark.ml.feature.VectorAssembler
import org.apache.spark.mllib.evaluation.{BinaryClassificationMetrics, MulticlassMetrics}
import org.apache.spark.sql.{Row, SparkSession}
import org.apache.spark.sql.functions.{col, lit, max, udf}
import org.apache.spark.sql.types.DoubleType

import scala.util.hashing.MurmurHash3

/**
  * Ex6
  *
  * 実行方法:
  *   sbt assembly
  *   SPARK_LOCAL_IP=127.0.0.1 spark-submit --class sample.LrHashAndOnehotEnc target/scala-2.11/spark-sample-assembly-1.0.jar
  */
object LrHashAndOnehotEnc {

  def main(args: Array[String]) = {
    val spark = SparkSession
      .builder()
      .appName("Basic LrHashAndOnehotEnc")
      .getOrCreate()

    spark.sparkContext.setLogLevel("WARN")

    // train data
    val trainDf = spark.createDataFrame(Seq(
      (1.0, 0L, 3, 5, "e3ed9bfe-c6a3-4dc2-8651-317657785755"),
      (0.0, 1L, 2, 5, "dc447571-9bc3-4b67-ad46-e7e873fc735a"),
      (0.0, 2L, 5, 5, "e2a1526a-c08f-4013-9ccb-065120f51dc4"),
      (1.0, 3L, 5, 5, "9a793b7d-f00f-484b-a6a5-833785207a58"),
      (0.0, 4L, 2, 4, "e2a1526a-c08f-4013-9ccb-065120f51dc4")
    )).toDF("label", "id", "ad_id", "spot_id", "device_id")

    val encTrainDf = trainDf.select(
      col("*"),
      onehotEncode(col("ad_id"), lit(5)) as "enc_ad_id",
      onehotEncode(col("spot_id"), lit(5)) as "enc_spot_id",
      hashingTrick(col("device_id"), lit(1000)) as "hash_device_id"
    )

    // pipeline
    val assembler = new VectorAssembler()
      .setInputCols(Array("enc_ad_id", "enc_spot_id", "hash_device_id"))
      .setOutputCol("features")

    val lr = new LogisticRegression()
      .setMaxIter(1000)
      .setRegParam(0.001)
      .setStandardization(false)

    val pipeline = new Pipeline()
      .setStages(Array(assembler, lr))

    // train
    val model = pipeline.fit(encTrainDf)

    // save & load
    model.write.overwrite().save("./tmp_model/lr-hash-and-onehotenc")
    val sameModel = PipelineModel.load("./tmp_model/lr-hash-and-onehotenc")

    // test
    val testDf = spark.createDataFrame(Seq(
      (1.0, 0L, 3, 5, "e3ed9bfe-c6a3-4dc2-8651-317657785755"),
      (0.0, 1L, 2, 5, "2553999c-40b0-4d24-9a78-2d831fb99735"),
      (1.0, 2L, 4, 5, "3aaceb29-4c26-4ee1-949d-9eaa8b8a1019"),
      (0.0, 2L, 4, 5, "3aaceb29-4c26-4ee1-949d-9eaa8b8a1019")
    )).toDF("label", "id", "ad_id", "spot_id", "device_id")

    val encTestDf = testDf.select(
      col("*"),
      onehotEncode(col("ad_id"), lit(5)) as "enc_ad_id",
      onehotEncode(col("spot_id"), lit(5)) as "enc_spot_id",
      hashingTrick(col("device_id"), lit(1000)) as "hash_device_id"
    )

    // predict
    val predictedDf = sameModel.transform(encTestDf)

    predictedDf.show(20, false)

    // coef & intercept
    val lrModel = sameModel.stages.last.asInstanceOf[LogisticRegressionModel]
    println(s"coef: ${lrModel.coefficients.toDense}, intercept: ${lrModel.intercept}")

    // show summary (fileからloadしたmodelでsummaryを取るとエラーになる)
/*    val trainingSummary = lrModel.summary
    val objectiveHistory = trainingSummary.objectiveHistory
    objectiveHistory.foreach(loss => println(s"loss: $loss"))*/

    // show multi metrics
    val predictionAndLabels = predictedDf
      .select("prediction", "label")
      .rdd
      .map { case Row(prediction: Double, label: Double) =>
        (prediction, label)
      }
      .cache()

    val multiMetrics = new MulticlassMetrics(predictionAndLabels)
    println("confusionMatrix:")
    println(multiMetrics.confusionMatrix)

    println("accuracy:")
    println(multiMetrics.accuracy)

    println("precision:")
    println("0: " + multiMetrics.precision(0.0))
    println("1: " + multiMetrics.precision(1.0))

    println("recall:")
    println("0: " + multiMetrics.recall(0.0))
    println("1: " + multiMetrics.recall(1.0))

    println("fMeasure:")
    println("0: " + multiMetrics.fMeasure(0.0))
    println("1: " + multiMetrics.fMeasure(1.0))

    // show binary metrics
    val scoreAndLabels = predictedDf
      .select("rawPrediction", "label")
      .rdd
      .map { case Row(rawPrediction: Vector, label: Double) =>
        (rawPrediction(1), label)
      }
      .cache()

    val metrics = new BinaryClassificationMetrics(scoreAndLabels)

    println("auc:")
    println(metrics.areaUnderROC())

    // show logloss
    val binaryLogLossEvaluator = new BinaryLogLossEvaluator()
    val logloss = binaryLogLossEvaluator.evaluate(predictedDf)

    println("logloss:")
    println(logloss)

    spark.stop()
  }

  val onehotEncode = udf { (v: Int, numFeatures: Int) =>
    if (v < numFeatures)
      Vectors.sparse(numFeatures, Array(v), Array(1.0))
    else
      Vectors.sparse(numFeatures, Array.empty[Int], Array.empty[Double])
  }

  val hashingTrick = udf { (v: String, numFeatures: Int) =>
    def nonNegativeMod(x: Int, mod: Int): Int = {
      val rawMod = x % mod
      rawMod + (if (rawMod < 0) mod else 0)
    }

    val hash = MurmurHash3.stringHash(v)
    val index = nonNegativeMod(hash, numFeatures)

    Vectors.sparse(numFeatures, Array(index), Array(1.0))
  }

}
