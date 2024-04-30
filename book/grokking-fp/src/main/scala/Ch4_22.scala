object Ch4_22 {
  def main(args: Array[String]): Unit = {
    val words = List("haskell", "rust", "scala", "java", "ada")
    println(rankedWords(score, words))
    println(rankedWords(w => score(w) + bonus(w), words))
    println(rankedWords(w => score(w) + bonus(w) - penalty(w), words))
  }

  def rankedWords(
      wordScore: String => Int,
      words: List[String]
  ): List[String] = {
    words.sortBy(wordScore).reverse
  }

  def score(word: String): Int = word.replaceAll("a", "").length

  def bonus(word: String): Int = if (word.contains("c")) 5 else 0

  def penalty(word: String): Int = if (word.contains("s")) 7 else 0
}
