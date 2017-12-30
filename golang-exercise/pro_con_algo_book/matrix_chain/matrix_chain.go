package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)

	p := make([]int, n+1)
	for i := 0; i < n; i++ {
		p[i], p[i+1] = nextInt(sc), nextInt(sc)
	}

	memo := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		memo[i] = make([]int, n+1)
	}

	for l := 2; l <= n; l++ {
		for i := 1; i <= n-l+1; i++ {
			j := i + l - 1
			memo[i][j] = math.MaxInt32
			for k := i; k < j; k++ {
				memo[i][j] = min(memo[i][j], memo[i][k]+memo[k+1][j]+p[i-1]*p[k]*p[j])
			}
		}
	}

	fmt.Println(memo[1][n])
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
