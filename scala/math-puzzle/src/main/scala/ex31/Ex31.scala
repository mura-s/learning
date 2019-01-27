package ex31

object Ex31 extends App {
  val length = 6
  val isUsed = Array.fill(length + 1)(Array.fill(length + 1)(Array.fill(2)(false)))
  var count = 0

  def route(x: Int, y: Int, isFirstTime: Boolean): Unit = {
    if (x == length && y == length) {
      if (isFirstTime) {
        route(0, 0, false)
      } else {
        count += 1
      }
    }

    if (x < length) {
      if (!isUsed(x)(y)(0)) {
        isUsed(x)(y)(0) = true
        route(x + 1, y, isFirstTime)
        isUsed(x)(y)(0) = false
      }
    }

    if (y < length) {
      if (!isUsed(x)(y)(1)) {
        isUsed(x)(y)(1) = true
        route(x, y + 1, isFirstTime)
        isUsed(x)(y)(1) = false
      }
    }
  }

  route(0, 0, true)
  println(count)
}
