package ex5

object Ex5 {

  def main(args: Array[String]) = {
    var count = 0

    for (coin500 <- 0 to 2;
         coin100 <- 0 to 10;
         coin50  <- 0 to 15;
         coin10  <- 0 to 15) {
      if (coin500 + coin100 + coin50 + coin10 <= 15) {
        if (coin500 * 500 + coin100 * 100 + coin50 * 50 + coin10 * 10 == 1000) {
          count += 1
        }
      }
    }

    println(count)
  }
}
