package ch5

func BitSwapRequired(a, b int) int {
	count := 0
	for c := a ^ b; c != 0; c = c >> 1 {
		count += c & 1
	}
	return count
}
