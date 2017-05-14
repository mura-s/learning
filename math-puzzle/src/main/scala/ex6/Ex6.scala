package ex6

object Ex6 {

  def main(args: Array[String]) = {
    var count = 0

    for (i <- 2 to 10000 by 2) {
      var n = i * 3 + 1
      while (n != 1 && n != i) {
        n = if (n % 2 == 0) n / 2 else n * 3 + 1
      }
      if (n == i) count += 1
    }

    println(count)
  }
}
