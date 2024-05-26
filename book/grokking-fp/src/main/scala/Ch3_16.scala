object Ch3_16 {
  def main(args: Array[String]): Unit = {
    println(abbreviate("Alonzo Church"))
    println(abbreviate("A. Church"))
    println(abbreviate("A Church"))
  }

  def abbreviate(name: String): String = {
    val initial = name.substring(0, 1)
    val separator = name.indexOf(" ")
    val lastName = name.substring(separator + 1)
    initial + ". " + lastName
  }
}
