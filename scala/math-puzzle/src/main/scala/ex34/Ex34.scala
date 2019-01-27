package ex34

import scala.collection.mutable

object Ex34 extends App {
  val board = Array.fill(11)(Array.fill(11)(false))
  board.zipWithIndex.foreach { case (arr, i) =>
    arr.zipWithIndex.foreach { case (b, j) =>
      board(i)(j) = i == 0 || i == 10 || j == 0 || j == 10
    }
  }

  var count = 0

  def search(y: Int, x: Int, dy: Int, dx: Int, check: mutable.Map[Int, Int]): Unit = {
    if (!board(y)(x)) {
      check(y * 10 + x) = 1
      search(y + dy, x + dx, dy, dx, check)
    }
  }

  for (hy <- 1 to 9) {
    for (hx <- 1 to 9) {
      for (ky <- 1 to 9) {
        for (kx <- 1 to 9) {
          if (hy != ky || hx != kx) {
            board(hy)(hx) = true
            board(ky)(kx) = true
            val check = mutable.Map[Int, Int]()

            List((-1, 0), (1, 0), (0, -1), (0, 1)).foreach { case (hdy, hdx) =>
              search(hy + hdy, hx + hdx, hdy, hdx, check)
            }

            List((-1, -1), (-1, 1), (1, -1), (1, 1)).foreach { case (kdy, kdx) =>
              search(ky + kdy, kx + kdx, kdy, kdx, check)
            }

            count += check.size

            board(hy)(hx) = false
            board(ky)(kx) = false
          }
        }
      }
    }
  }

  println(count)
}
