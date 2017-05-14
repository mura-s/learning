package ex13

object Ex13 {

  def main(args: Array[String]) = {
    var count = 0
    (0 to 9).permutations.foreach { case Seq(r, e, a, d, w, i, t, l, k, s) =>
      if (r != 0 && w != 0 && t != 0 && s != 0) {
        val read = r * 1000 + e * 100 + a * 10 + d
        val write = w * 10000 + r * 1000 + i * 100 + t * 10 + e
        val talk = t * 1000 + a * 100 + l * 10 + k
        val skill = s * 10000 + k * 1000 + i * 100 + l * 10 + l
        if (read + write + talk == skill) {
          count += 1
          println(s"${read} + ${write} + ${talk} = ${skill}")
        }
      }
    }
    println(count)
  }
}
