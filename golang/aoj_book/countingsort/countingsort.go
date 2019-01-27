package main

import (
	"bufio"
	"fmt"
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

	k := 0
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(sc)
		if k < a[i] {
			k = a[i]
		}
	}
	k++

	b := make([]int, n)
	countingsort(a, b, n, k)

	for i, v := range b {
		if i != 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", v)
	}
	fmt.Println("")
}

func countingsort(a, b []int, n, k int) {
	c := make([]int, k)

	for j := 0; j < n; j++ {
		c[a[j]]++
	}

	for i := 1; i < k; i++ {
		c[i] += c[i-1]
	}

	for j := n - 1; j >= 0; j-- {
		b[c[a[j]]-1] = a[j]
		c[a[j]]--
	}
}
