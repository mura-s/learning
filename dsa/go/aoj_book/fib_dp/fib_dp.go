package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var memo [100]int

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)

	memo[0] = 1
	memo[1] = 1
	fmt.Println(fib(n))
}

func fib(n int) int {
	if memo[n] > 0 {
		return memo[n]
	}
	memo[n] = fib(n-1) + fib(n-2)
	return memo[n]
}
