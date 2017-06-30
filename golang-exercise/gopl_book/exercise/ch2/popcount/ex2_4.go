package popcount

func PopCount2_4(x uint64) int {
	count := 0
	for i := 0; i < 64; i++ {
		if (x & 1) == 1 {
			count++
		}
		x >>= 1
	}
	return count
}
