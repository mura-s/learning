package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const (
	white = iota
	gray
	black
)

const inf = math.MaxInt32

var (
	graph  [][]int
	colors []int
	d      []int
	p      []int
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

	graph = make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, n)
	}
	makeGraph(sc, n)

	colors = make([]int, n)
	d = make([]int, n)
	for i := 0; i < n; i++ {
		d[i] = inf
	}
	p = make([]int, n)

	prim(n)
	print()
}

func makeGraph(sc *bufio.Scanner, n int) {
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			graph[i][j] = nextInt(sc)
		}
	}
}

func prim(n int) {
	d[0] = 0
	p[0] = -1

	for {
		mincost := inf
		u := -1
		for i := 0; i < n; i++ {
			if colors[i] != black && d[i] < mincost {
				mincost = d[i]
				u = i
			}
		}

		if mincost == inf {
			break
		}

		colors[u] = black

		for v := 0; v < n; v++ {
			if colors[v] != black && graph[u][v] != -1 {
				if graph[u][v] < d[v] {
					d[v] = graph[u][v]
					p[v] = u
					colors[v] = gray
				}
			}
		}
	}
}

func print() {
	sum := 0
	for _, v := range d {
		sum += v
	}
	fmt.Println(sum)
}
