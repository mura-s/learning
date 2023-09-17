package ch1

// NxNの行列を90度回転させる
func Rotate(matrix [][]int, n int) {
	// 外枠から回転させていく
	for i := 0; i < n/2; i++ {

		for j := i; j < n-1-i; j++ {
			// 4つのセルを同時に回転させる
			matrix[i][j], matrix[j][n-1-i], matrix[n-1-i][n-1-j], matrix[n-1-j][i] =
				matrix[n-1-j][i], matrix[i][j], matrix[j][n-1-i], matrix[n-1-i][n-1-j]
		}
	}
}
