package ex15

object Ex15 extends App {
  val (aStartPos, bStartPos) = (0, 10)
  var count = 0

  def move(aPos: Int, bPos: Int): Unit = {
    for (a <- 1 to 4;
         b <- 1 to 4) {
      val aMovedPos = aPos + a
      val bMovedPos = bPos - b

      if (aMovedPos == bMovedPos)
        count += 1
      else if (aMovedPos < bMovedPos)
        move(aMovedPos, bMovedPos)
    }
  }

  move(aStartPos, bStartPos)
  println(count)
}
