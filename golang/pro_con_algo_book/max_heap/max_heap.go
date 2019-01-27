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

	heap := make([]int, n+1)
	for i := 1; i <= n; i++ {
		heap[i] = nextInt(sc)
	}

	buildMaxHeap(heap, n)
	print(heap)
}

func buildMaxHeap(heap []int, n int) {
	for i := len(heap) / 2; i >= 1; i-- {
		maxHeapify(heap, n, i)
	}
}

func maxHeapify(heap []int, n, i int) {
	l := left(i)
	r := right(i)

	largest := i
	if l <= n && heap[l] > heap[largest] {
		largest = l
	}
	if r <= n && heap[r] > heap[largest] {
		largest = r
	}

	if largest != i {
		heap[largest], heap[i] = heap[i], heap[largest]
		maxHeapify(heap, n, largest)
	}
}

func left(i int) int {
	return 2 * i
}

func right(i int) int {
	return 2*i + 1
}

func print(heap []int) {
	for i, v := range heap {
		if i == 0 {
			continue
		}
		fmt.Printf(" %d", v)
	}
	fmt.Println("")
}
