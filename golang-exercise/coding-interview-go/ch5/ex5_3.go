package ch5

func GetNextAndPrev(num int) (next, prev int) {
	count := bitCount(num)

	for next = num + 1; bitCount(next) != count; next++ {
	}

	for prev = num - 1; bitCount(prev) != count; prev-- {
	}

	return
}

func bitCount(num int) int {
	count := 0
	for num > 0 {
		if (num & 1) == 1 {
			count++
		}
		num = num >> 1
	}
	return count
}
