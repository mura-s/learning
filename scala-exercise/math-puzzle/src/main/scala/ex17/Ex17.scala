package ex17

object Ex17 extends App {
  val Max = 30
  var count = 0
  for (girl <- 0 to Max / 2) {
    count += (0 to Max - girl).combinations(girl).length
  }
  println(count)
}
