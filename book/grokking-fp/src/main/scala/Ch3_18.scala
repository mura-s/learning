object Ch3_18 {
  def main(args: Array[String]): Unit = {
    val planA = List("Paris", "Berlin", "Krakow")
    val planB = replan(planA, "Vienna", "Krakow")
    println(planA)
    println(planB)
  }

  def replan(
      plan: List[String],
      newCity: String,
      beforeCity: String
  ): List[String] = {
    val beforeCityIndex = plan.indexOf(beforeCity)
    val citiesBefore = plan.slice(0, beforeCityIndex)
    val citiesAfter = plan.slice(beforeCityIndex, plan.size)
    citiesBefore.appended(newCity).appendedAll(citiesAfter)
  }
}
