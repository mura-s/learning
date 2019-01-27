package ch1

// MxNの行列で、要素が0ならその行と列の全ての要素を0にする
func SetZeroToMatrix(matrix [][]int) {
	row, col := len(matrix), len(matrix[0])
	zeroRow := make([]bool, row)
	zeroCol := make([]bool, col)

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if matrix[i][j] == 0 {
				zeroRow[i] = true
				zeroCol[j] = true
			}
		}
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if zeroRow[i] || zeroCol[j] {
				matrix[i][j] = 0
			}
		}
	}
}
