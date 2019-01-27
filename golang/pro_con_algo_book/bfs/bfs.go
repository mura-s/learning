package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
	"strconv"
)

var (
	graph   [][]int
	queue   *list.List
	d       []int
	visited []bool
)

type nodeDistance struct {
	idx int
	d   int
}

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
	queue = list.New()
	d = make([]int, n)
	visited = make([]bool, n)

	for i := 0; i < n; i++ {
		graph[i] = make([]int, n)
		d[i] = -1
	}

	makeGraph(sc, n)
	bfs(n)
	print(n)
}

func makeGraph(sc *bufio.Scanner, n int) {
	for i := 0; i < n; i++ {
		u := nextInt(sc)
		k := nextInt(sc)
		for j := 0; j < k; j++ {
			v := nextInt(sc)
			graph[u-1][v-1] = 1
		}
	}
}

func bfs(n int) {
	queue.PushBack(&nodeDistance{0, 0})

	for queue.Len() != 0 {
		elem := queue.Remove(queue.Front())
		nd := elem.(*nodeDistance)
		d[nd.idx] = nd.d

		for j := 0; j < n; j++ {
			if !visited[j] && graph[nd.idx][j] == 1 {
				queue.PushBack(&nodeDistance{j, nd.d + 1})
				visited[j] = true
			}
		}
	}
}

func print(n int) {
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d\n", i+1, d[i])
	}
}
