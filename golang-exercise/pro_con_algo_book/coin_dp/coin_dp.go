package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const inf = math.MaxInt32

var (
	t []int
	c []int
)

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n, m := nextInt(sc), nextInt(sc)

	c = make([]int, m)
	for i := 0; i < m; i++ {
		c[i] = nextInt(sc)
	}

	t = make([]int, n+1)
	for i := 1; i <= n; i++ {
		t[i] = inf
	}

	for i := 0; i < m; i++ {
		for j := c[i]; j <= n; j++ {
			t[j] = min(t[j], t[j-c[i]]+1)
		}
	}

	fmt.Println(t[n])
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
