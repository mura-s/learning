object Ch3_19 {
  def main(args: Array[String]): Unit = {
    println(firstTwo(List("a", "b", "c", "d")))
    println(lastTwo(List("a", "b", "c", "d")))
    println(movedFirstTwoToTheEnd(List("a", "b", "c", "d")))
    println(insertedBeforeLast(List("a", "b", "c", "d"), "e"))
  }

  def firstTwo(list: List[String]): List[String] =
    list.slice(0, 2)

  def lastTwo(list: List[String]): List[String] =
    list.slice(list.size - 2, list.size)

  def movedFirstTwoToTheEnd(list: List[String]): List[String] =
    list.slice(2, list.size).appendedAll(firstTwo(list))

  def insertedBeforeLast(list: List[String], element: String): List[String] =
    list
      .slice(0, list.size - 1)
      .appended(element)
      .appendedAll(list.slice(list.size - 1, list.size))
}
