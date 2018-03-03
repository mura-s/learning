package ex3

object Ex3 {

  def main(args: Array[String]) = {
    val arr = Array.fill(101)(false)
    arr(0) = true

    for (i <- 2 to 100) {
      for (j <- i to 100 by i) {
        arr(j) = !arr(j)
      }
    }

    arr.zipWithIndex foreach {
      case (false, i) => println(i)
      case _ => ()
    }
  }
}
