package ex8

object Ex8 {

  def main(args: Array[String]) = {
    val N = 12

    def next(log: List[(Int, Int)]): Int = {
      if (log.size > N) return 1

      var count = 0
      List((1, 0), (0, 1), (-1, 0), (0, -1)).foreach {
        case (dx, dy) =>
          val nextPos = (log.last._1 + dx, log.last._2 + dy)
          if (!log.contains(nextPos)) count += next(log :+ nextPos)
      }

      count
    }

    println(next(List((0, 0))))
  }
}
