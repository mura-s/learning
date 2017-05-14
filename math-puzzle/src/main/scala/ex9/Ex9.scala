package ex9

object Ex9 {

  def main(args: Array[String]) = {
    val (boy, girl) = (21, 11)
    val ary = Array.ofDim[Int](boy, girl)
    ary(0)(0) = 1
    for (i <- 0 until boy;
         j <- 0 until girl) {
      if ((i != j) && (boy - i != girl - j)) {
        if (j > 0) {
          ary(i)(j) += ary(i)(j - 1)
        }
        if (i > 0) {
          ary(i)(j) += ary(i - 1)(j)
        }
      }
    }

    println(ary(boy - 2)(girl - 1) + ary(boy - 1)(girl - 2))
  }

}
