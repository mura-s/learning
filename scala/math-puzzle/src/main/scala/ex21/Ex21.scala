package ex21

import scala.collection.mutable.ArrayBuffer

object Ex21 extends App {
  val triangle = ArrayBuffer[ArrayBuffer[Int]]()

  var line = 0
  var zeroCount = 0
  while (zeroCount < 2014) {
    for (j <- 0 to line) {
      if (j == 0) triangle += ArrayBuffer(1)
      else if (j == line) triangle(line) += 1
      else {
        val prev = triangle(line - 1)
        val v = prev(j - 1) ^ prev(j)
        if (v == 0) zeroCount += 1
        triangle(line) += v
      }
    }

    line += 1
  }

  println(line)
}
