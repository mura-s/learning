package ex14

object Ex14 {

  def main(args: Array[String]) = {
    val country = Array(
      "brazil", "croatia", "mexico", "cameroon",
      "spain", "netherlands", "chile", "australia",
      "colombia", "greece", "cote d'ivoire", "japan",
      "uruguay", "costa rica", "england", "italy",
      "switzerland", "ecuador", "france", "honduras",
      "argentina", "bosnia and herzegovina", "iran", "nigeria",
      "germany", "portugal", "ghana", "usa",
      "belgium", "algeria", "russia", "korea republic"
    )

    val isUsed = Array.fill(country.length)(false)
    var maxDepth = 0

    def search(prev: String, depth: Int): Unit = {
      var isLast = true
      country.zipWithIndex.foreach { case (str, i) =>
        if (str.head == prev.last && !isUsed(i)) {
          isLast = false
          isUsed(i) = true
          search(str, depth + 1)
          isUsed(i) = false
        }
      }
      if (isLast) maxDepth = Array(maxDepth, depth).max
    }

    country.zipWithIndex.foreach { case (str, i) =>
      isUsed(i) = true
      search(str, 1)
      isUsed(i) = false
    }

    println(maxDepth)
  }
}
