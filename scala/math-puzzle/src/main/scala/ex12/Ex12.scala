package ex12

object Ex12 {

  def main(args: Array[String]) = {
    def loop1(i: Int): Int = {
      val str = Math.sqrt(i.toDouble).toString.replace(".", "")
      val substr = if (str.length > 10) str.substring(0, 10) else str

      if (substr.split("").distinct.length == 10) i else loop1(i + 1)
    }

    def loop2(i: Int): Int = {
      val str = Math.sqrt(i.toDouble).toString.replace(".", "").substring(1)
      val substr = if (str.length > 10) str.substring(0, 10) else str

      if (substr.split("").distinct.length == 10) i else loop2(i + 1)
    }

    println(loop1(1))
    println(loop2(1))
  }
}
