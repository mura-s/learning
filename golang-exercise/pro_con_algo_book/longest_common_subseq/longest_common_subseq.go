package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var memo [100][100]int

func next(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n, _ := strconv.Atoi(next(sc))

	for i := 0; i < n; i++ {
		memo = [100][100]int{}
		x := next(sc)
		y := next(sc)
		fmt.Println(lcs(x, y))
	}
}

func lcs(x, y string) int {
	m := len(x)
	n := len(y)
	maxLen := 0

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if x[i-1] == y[j-1] {
				memo[i][j] = memo[i-1][j-1] + 1
			} else {
				memo[i][j] = max(memo[i-1][j], memo[i][j-1])
			}

			maxLen = max(maxLen, memo[i][j])
		}
	}

	return maxLen
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
