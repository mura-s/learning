object ShoppingCart {
  def main(args: Array[String]): Unit = {
    println(getDisountPercentage(List("Apple")))
    println(getDisountPercentage(List("Apple", "Book")))
  }

  def getDisountPercentage(items: List[String]): Int =
    if (items.contains("Book")) 5 else 0
}
