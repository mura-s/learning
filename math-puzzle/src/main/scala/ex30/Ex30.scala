package ex30

import scala.collection.mutable

object Ex30 extends App {
  val N = 20
  val memo = mutable.Map(1 -> 1)

  def setTap(remain: Int): Int = {
    if (memo.contains(remain)) {
      memo(remain)
    } else {
      var cnt = 0
      for (i <- 1 to remain / 2) {
        cnt += setTap(remain - i) * setTap(i)
      }

      for (i <- 1 to remain / 3) {
        for (j <- 1 to (remain - i) / 2) {
          cnt += setTap(remain - (i + j)) * setTap(j) * setTap(i)
        }
      }

      memo.put(remain, cnt)
      cnt
    }
  }

  println(setTap(N))
}
