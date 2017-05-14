package ex19

object Ex19 extends App {
  val primes = Seq(2, 3, 5, 7, 11, 13)
  var min = primes.last * primes.last
  var minFriend = Seq[Int]()

  primes.permutations.foreach { permPrimes =>
    val friends = permPrimes.zipWithIndex.map { case (v, i) =>
      if (i == 0) v * v
      else v * permPrimes(i - 1)
    } :+ (permPrimes.last * permPrimes.last)

    if (friends.max < min) {
      min = friends.max
      minFriend = friends
    }
  }

  println(min)
  println(minFriend)
}
