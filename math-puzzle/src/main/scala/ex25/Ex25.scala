package ex25

import scala.collection.mutable.ArrayBuffer

object Ex25 extends App {
  val N = 6
  var maxCount = 0
  (1 until N).permutations.foreach { l =>
    (1 until N).permutations.foreach { r =>
      val path = ArrayBuffer[(Int, Int)]()
      var left = 0
      var right = r(0)
      for (i <- 0 to N - 2) {
        path += left -> right
        left = l(i)
        path += left -> right
        if (i + 1 < r.length) right = r(i + 1)
      }
      path += left -> 0

      var count = 0
      for (i <- 0 until N * 2) {
        for (j <- i + 1 to N * 2 - 2) {
          if ((path(i)._1 - path(j)._1) * (path(i)._2 - path(j)._2) < 0) count += 1
        }
      }
      maxCount = if (maxCount < count) count else maxCount
    }
  }

  println(maxCount)
}
