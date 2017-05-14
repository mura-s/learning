package ex36

object Ex36 extends App {
  var ns = (1 to 50).filterNot(i => i % 2 == 0 || i % 5 == 0).toBuffer
  var k = 1
  while (ns.nonEmpty) {
    val x = k.toBinaryString.toLong * 7
    if (x.toString.contains("0")) {
      ns.foreach { n =>
        if (x % n == 0) {
          if (x.toString == x.toString.reverse) println(n)
          ns = ns.filterNot(_ == n)
        }
      }
    }
    k += 1
  }
}
