package ex33

import scala.io.Source

object Ex33 {
  def main(args: Array[String]) = {
    var count = 0

    def search(list: Array[String], len: Int): Unit = {
      if (list.length == 1) {
        count += len - 1
      } else {
        list.map(_.take(len)).distinct.foreach { str =>
          search(list.filter(_.startsWith(str.take(len))), len + 1)
        }
      }
    }

    val lines = Source.fromFile(args(0)).getLines()
    lines.drop(1).map { line =>
      val ary = line.split(",")
      Array(ary(3), ary(4))
    }.toArray.transpose.foreach(search(_, 1))

    println(count)
  }
}
