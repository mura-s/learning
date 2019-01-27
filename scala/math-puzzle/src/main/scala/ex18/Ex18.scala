package ex18

object Ex18 extends App {
  def check(n: Int, pre: Int, log: Seq[Int], square: Seq[Int]): Boolean = {
    if (n == log.length) {
      if (square.contains(1 + pre)) return true
    } else {
      (1 to n).diff(log).foreach { i =>
        if (square.contains(pre + i)) {
          if (check(n, i, log :+ i, square)) return true
        }
      }
    }
    false
  }

  def loop(n: Int): Int = {
    val square = (2 to n).map(i => i * i)
    if (check(n, 1, Seq(1), square)) n else loop(n + 1)
  }

  println(loop(2))
}
