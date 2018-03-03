package ex24

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer

object Ex24 extends App {
  val board = ArrayBuffer[Seq[Int]](
    Seq(1, 2), Seq(2, 3), Seq(7, 8), Seq(8, 9),
    Seq(1, 4), Seq(3, 6), Seq(4, 7), Seq(6, 9)
  )
  for (i <- 1 to 9) {
    board += Seq(i)
  }

  val memo = mutable.Map(ArrayBuffer[Seq[Int]]() -> 1)

  def strike(board: ArrayBuffer[Seq[Int]]): Int = {
    if (memo.contains(board)) memo(board)
    else {
      var count = 0
      board.foreach { b =>
        val nextBoard = board.filter(s => b.diff(s).size == b.size)
        count += strike(nextBoard)
      }
      memo(board) = count
      count
    }
  }

  println(strike(board))
}
