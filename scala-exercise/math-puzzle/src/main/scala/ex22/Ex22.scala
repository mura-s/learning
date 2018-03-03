package ex22

object Ex22 extends App {
  val n = 16
  val pair = Array.fill(n / 2 + 1)(0)
  pair(0) = 1

  for (i <- 1 to n / 2) {
    pair(i) = 0
    for (j <- 0 until i) {
      pair(i) += pair(j) * pair(i - j - 1)
    }
  }

  println(pair(n / 2))
}
