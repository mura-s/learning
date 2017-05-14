package ex23

object Ex23 extends App {
  var count = 0

  def game(nCoins: Int, nGames: Int): Unit = {
    if (nGames == 24) count += 1
    else if (nCoins == 0) ()
    else {
      game(nCoins + 1, nGames + 1)
      game(nCoins - 1, nGames + 1)
    }
  }

  game(10, 0)
  println(count)
}
