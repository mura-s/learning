package org.apache.spark.ml.evaluation

import org.apache.commons.math3.util.FastMath
import org.apache.spark.ml.param.ParamMap
import org.apache.spark.ml.param.shared.{HasLabelCol, HasProbabilityCol}
import org.apache.spark.ml.util.{Identifiable, SchemaUtils}
import org.apache.spark.ml.linalg.{Vector, VectorUDT}
import org.apache.spark.sql.types.DoubleType
import org.apache.spark.sql.{Dataset, Row}

class BinaryLogLossEvaluator(override val uid: String)
  extends Evaluator with HasProbabilityCol with HasLabelCol {

  def this() = this(Identifiable.randomUID("binLogLossEval"))

  def setProbabilityCol(value: String): this.type = set(probabilityCol, value)

  def setLabelCol(value: String): this.type = set(labelCol, value)

  override def evaluate(dataset: Dataset[_]): Double = {
    val schema = dataset.schema

    SchemaUtils.checkColumnType(schema, $(probabilityCol), new VectorUDT)
    SchemaUtils.checkColumnType(schema, $(labelCol), DoubleType)

    val epsilon = 1e-15
    val minusLogLoss = dataset
      .select($(probabilityCol), $(labelCol))
      .rdd
      .map { case Row(probabilities: Vector, label: Double) =>
        val tmpProb = Math.max(epsilon, probabilities(1))
        val probability = Math.min(1 - epsilon, tmpProb)
        label * FastMath.log(probability) + (1 - label) * FastMath.log(1 - probability)
      }
      .mean()

    -1.0 * minusLogLoss
  }

  override def isLargerBetter: Boolean = false

  override def copy(extra: ParamMap): BinaryLogLossEvaluator = defaultCopy(extra)
}
