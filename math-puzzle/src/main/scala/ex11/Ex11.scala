package ex11

object Ex11 {

  def main(args: Array[String]) = {
    var memo = Array[Long](1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144)
    var cnt = 0

    def fib(): Unit = {
      val num = memo(memo.length - 1) + memo(memo.length - 2)

      if (isDivisble(num)) {
        println(num)
        cnt += 1
      }

      if (cnt < 5) {
        memo = memo :+ num
        fib()
      }
    }

    def isDivisble(num: Long): Boolean =
      (num % num.toString.split("").map(_.toInt).sum) == 0

    fib()
  }
}
