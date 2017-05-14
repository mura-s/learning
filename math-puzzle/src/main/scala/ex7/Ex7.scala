package ex7

import org.joda.time.DateTime

object Ex7 {

  def main(args: Array[String]) = {
    var date = new DateTime(1964, 10, 10, 0, 0, 0)
    val lastDate = new DateTime(2020, 7, 24, 0, 0, 0)

    while (date.compareTo(lastDate) <= 0) {
      val dateStr = date.toString("yyyyMMdd")
      val reversedBinary = dateStr.toInt.toBinaryString.reverse
      val reversedDateStr = Integer.parseInt(reversedBinary, 2).toString

      if (dateStr == reversedDateStr) println(dateStr)

      date = date.plusDays(1)
    }
  }
}
