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

	makeGraph(sc, n)
	colors = make([]int, n)
	d = make([]int, n)
	for i := 0; i < n; i++ {
		d[i] = inf
	}
	p = make([]int, n)

	dijkstra(n)
	print()
}

func makeGraph(sc *bufio.Scanner, n int) {
	graph = make([][]int, n)

	for i := 0; i < n; i++ {
		graph[i] = make([]int, n)

		for j := 0; j < n; j++ {
			graph[i][j] = inf
		}
	}

	for i := 0; i < n; i++ {
		_ = nextInt(sc)
		k := nextInt(sc)
		for j := 0; j < k; j++ {
			v, c := nextInt(sc), nextInt(sc)
			graph[i][v] = c
		}
	}
}

func dijkstra(n int) {
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
				if d[u]+graph[u][v] < d[v] {
					d[v] = d[u] + graph[u][v]
					p[v] = u
					colors[v] = gray
				}
			}
		}
	}
}

func print() {
	for i, v := range d {
		fmt.Printf("%d %d\n", i, v)
	}
}
