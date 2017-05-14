package ex10

object Ex10 {

  def main(args: Array[String]) = {
    val euro = Array(
      0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13,
      36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14,
      31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26
    )

    val euroLen = euro.length
    val american = Array(
      0, 28, 9, 26, 30, 11, 7, 20, 32, 17, 5, 22, 34,
      15, 3, 24, 36, 13, 1, 0, 27, 10, 25, 29, 12, 8,
      19, 31, 18, 6, 21, 33, 16, 4, 23, 35, 14, 2
    )
    val ameLen = american.length

    var result = 0

    for (n <- 2 to 36) {
      val euroMax = calcMax(euro, euroLen, n)
      val ameMax = calcMax(american, ameLen, n)
      if (euroMax < ameMax) result += 1
    }

    println(result)
  }

  def calcMax(ary: Array[Int], len: Int, n: Int): Int = {
    var max = 0

    ary.zipWithIndex.foreach { case (_, idx) =>
      var tmp = 0
      for (i <- 0 until n) {
        tmp += ary((idx + i) % len)
      }
      if (max < tmp) max = tmp
    }

    max
  }
}
