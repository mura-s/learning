package ex16

import scala.collection.mutable.ArrayBuffer

object Ex16 extends App {
  val Max = 500
  val answer = new ArrayBuffer[Seq[Double]]()

  (1 to Max / 4).foreach { c =>
    val edge = (1 until c).map(j => j * (2 * c - j))
    edge.combinations(2).foreach { case Seq(a, b) =>
      if (a + b == c * c) {
        answer.append(Seq(1.toDouble, b / a.toDouble, c * c / a.toDouble))
      }
    }
  }

  println(answer.distinct.length)
}
