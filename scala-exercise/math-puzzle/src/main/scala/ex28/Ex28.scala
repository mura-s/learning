package ex28

object Ex28 extends App {
  val club = Seq(
    11000 -> 40, 8000 -> 30, 400 -> 24, 800 -> 20, 900 -> 14,
    1800 -> 16, 1000 -> 15, 7000 -> 40, 100 -> 10, 300 -> 12
  )
  val N = 150
  val area = Array.fill(club.size + 1)(Array.fill(N + 1)(0))

  for (i <- club.indices) {
    for (j <- 0 to 150) {
      if (j < club(i)._2) area(i + 1)(j) = area(i)(j)
      else area(i + 1)(j) = Seq(area(i)(j), area(i)(j - club(i)._2) + club(i)._1).max
    }
  }

  println(area(club.size)(N))
}
