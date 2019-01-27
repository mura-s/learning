package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var count int

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

	mergesort(a, 0, len(a))

	for i, v := range a {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(v)
	}
	fmt.Printf("\n%d\n", count)
}

func mergesort(a []int, left, right int) {
	if left+1 < right {
		mid := (left + right) / 2
		mergesort(a, left, mid)
		mergesort(a, mid, right)
		merge(a, left, mid, right)
	}
}

func merge(a []int, left, mid, right int) {
	n1 := mid - left
	n2 := right - mid

	l := make([]int, n1+1)
	r := make([]int, n2+1)
	for i := 0; i < n1; i++ {
		l[i] = a[left+i]
	}
	for i := 0; i < n2; i++ {
		r[i] = a[mid+i]
	}
	l[n1] = math.MaxInt32
	r[n2] = math.MaxInt32

	i, j := 0, 0
	for k := left; k < right; k++ {
		if l[i] <= r[j] {
			a[k] = l[i]
			i += 1
		} else {
			a[k] = r[j]
			j += 1
		}

		count += 1
	}
}
