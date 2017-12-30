package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	heap = [10000]int{}
	size = 0
)

func next(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	for {
		op := next(sc)
		switch op {
		case "insert":
			k, _ := strconv.Atoi(next(sc))
			insert(k)
		case "extract":
			fmt.Println(extractMax())
		case "end":
			return
		}
	}
}

func insert(k int) {
	size++
	heap[size] = k

	i := size
	pID := parent(size)
	for pID >= 1 && heap[i] > heap[pID] {
		heap[i], heap[pID] = heap[pID], heap[i]
		i = pID
		pID = parent(pID)
	}
}

func extractMax() int {
	if size < 1 {
		panic("empty heap")
	}
	extracted := heap[1]
	heap[1] = heap[size]
	size--

	maxHeapify(size, 1)

	return extracted
}

func maxHeapify(n, i int) {
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
		maxHeapify(n, largest)
	}
}

func parent(idx int) int {
	return idx / 2
}

func left(i int) int {
	return 2 * i
}

func right(i int) int {
	return 2*i + 1
}
