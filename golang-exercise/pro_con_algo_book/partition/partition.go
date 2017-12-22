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

	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(sc)
	}

	q := partition(a, 0, n-1)

	for i, v := range a {
		if i != 0 {
			fmt.Printf(" ")
		}
		if i == q {
			fmt.Printf("[%d]", v)
		} else {
			fmt.Printf("%d", v)
		}
	}
	fmt.Println("")
}

func partition(a []int, p, r int) int {
	x := a[r]
	i := p
	for j := p; j < r; j++ {
		if a[j] <= x {
			a[i], a[j] = a[j], a[i]
			i++
		}
	}
	a[i], a[r] = a[r], a[i]
	return i
}
