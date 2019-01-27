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

	nodes := make([]int, n)
	for i := 0; i < n; i++ {
		nodes[i] = nextInt(sc)
	}

	for i, v := range nodes {
		idx := i + 1
		fmt.Printf("node %d: key = %d, ", idx, v)

		pIdx := parent(idx) - 1
		if pIdx >= 0 {
			fmt.Printf("parent key = %d, ", nodes[pIdx])
		}

		leftIdx := left(idx) - 1
		if leftIdx < n {
			fmt.Printf("left key = %d, ", nodes[leftIdx])
		}

		rightIdx := right(idx) - 1
		if rightIdx < n {
			fmt.Printf("right key = %d, ", nodes[rightIdx])
		}

		fmt.Println("")
	}
}

func parent(idx int) int {
	return idx / 2
}

func left(idx int) int {
	return 2 * idx
}

func right(idx int) int {
	return 2*idx + 1
}
