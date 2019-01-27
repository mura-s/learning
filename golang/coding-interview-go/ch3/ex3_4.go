package ch3

// ハノイの塔
func Hanoi(tower1, tower2, tower3 *Stack) {
	moveDisks(len(tower1.buf), tower1, tower2, tower3)
}

func moveDisks(n int, src, buffer, dist *Stack) {
	if n <= 0 {
		return
	}

	moveDisks(n-1, src, dist, buffer)
	moveTop(src, dist)
	moveDisks(n-1, buffer, src, dist)
}

func moveTop(src, dist *Stack) {
	dist.Push(src.Pop())
}
