package popcount

func PopCount2_5(x uint64) int {
	count := 0
	for x != 0 {
		count++
		x &= (x - 1)
	}
	return count
}
