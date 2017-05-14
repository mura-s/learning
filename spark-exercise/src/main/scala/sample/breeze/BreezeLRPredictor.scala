package sample.breeze

import breeze.linalg.{DenseVector, SparseVector}
import breeze.numerics.sigmoid

/**
  * Breeze Ex1
  *
  * Spark側の sample.BasicLogisticRegression1 に対応
  *
  * Sparkでのpredictと同じ結果になることを確認
  */
object BreezeLRPredictor {

  def main(args: Array[String]) = {
    // DenseVector
    val w = DenseVector(-1.628998081132571, 0.008488040503005827, -0.09395971517916687)
    val x = DenseVector(-1.0, 1.5, 1.3)
    val a = w.dot(x) + 1.6085311916097589
    val prob = sigmoid(a)

    println(prob)

    // SparseVector
    val ws = SparseVector(3)((0, -1.628998081132571), (1, 0.008488040503005827), (2, -0.09395971517916687))
    val xs = SparseVector(3)((0, -1.0), (1, 1.5), (2, 1.3))
    val as = ws.dot(xs) + 1.6085311916097589
    val probs = sigmoid(as)

    println(probs)

    // Dense x Sparse
    val ax = w.dot(xs) + 1.6085311916097589
    val probx = sigmoid(ax)
    println(probx)
  }

}
