package ex20

import scala.collection.mutable

object Ex20 extends App {
  val magicSquare = Seq(1, 14, 14, 4, 11, 7, 6, 9, 8, 10, 10, 5, 13, 2, 3, 15)
  val map = mutable.Map[Int, Int]()
  for (i <- 1 to magicSquare.length) {
    magicSquare.combinations(i).foreach { v =>
      val key = v.sum
      map.put(key, map.getOrElse(key, 0) + 1)
    }
  }
  println(map.maxBy(_._2))
}
