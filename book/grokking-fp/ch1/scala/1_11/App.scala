object App {
  def main(args: Array[String]): Unit = {
    println(increment(1))
    println(getFirstCharacter("hello"))
    println(wordScore("hello"))
  }

  def increment(x: Int): Int = x + 1

  def getFirstCharacter(s: String): Char = s.charAt(0)

  def wordScore(word: String): Int = word.length()
}
