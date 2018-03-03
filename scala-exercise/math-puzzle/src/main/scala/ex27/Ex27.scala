package ex27

object Ex27 extends App {
  val W = 6
  val H = 4
  val Dir = Seq(0 -> 1, -1 -> 0, 0 -> -1, 1 -> 0)
  val left = Array.fill(H)(0)
  val bottom = Array.fill(W)(0)

  def search(x: Int, y: Int, dir: Int, left: Array[Int], bottom: Array[Int]): Int = {
    val left_l = left.clone()
    val bottom_l = bottom.clone()
    if (dir == 0 || dir == 2) {
      val pos = Seq(y, y + Dir(dir)._2).min
      if (pos < 0 || y + Dir(dir)._2 > H) return 0
      if ((left_l(pos) & (1 << x)) > 0) return 0
      left_l(pos) |= (1 << x)
    } else {
      val pos = Seq(x, x + Dir(dir)._1).min
      if (pos < 0 || x + Dir(dir)._1 > W) return 0
      if ((bottom_l(pos) & (1 << y)) > 0) return 0
      bottom_l(pos) |= (1 << y)
    }
    val nextX = x + Dir(dir)._1
    val nextY = y + Dir(dir)._2

    if (nextX == W && nextY == H) return 1

    var cnt = 0
    cnt += search(nextX, nextY, dir, left_l, bottom_l)
    cnt += search(nextX, nextY, (dir + 1) % Dir.size, left_l, bottom_l)
    cnt
  }

  println(search(0, 0, 3, left, bottom))
}
