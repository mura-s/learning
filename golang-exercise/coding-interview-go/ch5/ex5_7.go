package ch5

// 本来はbit演算を使って解く必要がある。
func FindMissingNum(array []int) int {
	l := len(array)

	arraySum, sum := 0, 0
	for i := 0; i <= l; i++ {
		if i != l {
			arraySum += array[i]
		}
		sum += i
	}

	return sum - arraySum
}
