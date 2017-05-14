package ex1

import scala.annotation.tailrec

object Ex1 {

  def main(args: Array[String]) = {
    @tailrec
    def loop(n: Int): Int =
      if (isPalindrome(n.toString) &&
        isPalindrome(n.toBinaryString) &&
        isPalindrome(n.toOctalString)
      ) n else loop(n + 2)

    def isPalindrome(n: String): Boolean = n == n.reverse

    println(loop(11))
  }
}
