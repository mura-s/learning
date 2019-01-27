package ex4

object Ex4 {

  def main(args: Array[String]) = {
    println(cutbar(20, 3, 1))
    println(cutbar(100, 5, 1))
  }

  def cutbar(n: Int, m: Int, current: Int): Int = {
    if (current >= n) {
      0
    } else if (current < m) {
      1 + cutbar(n, m, current * 2)
    } else {
      1 + cutbar(n, m, current + m)
    }
  }
}
