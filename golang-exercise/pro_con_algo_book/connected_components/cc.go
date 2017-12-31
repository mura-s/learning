package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
	"strconv"
)

var (
	graph   []*list.List
	visited []bool
)

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n, m := nextInt(sc), nextInt(sc)

	graph = make([]*list.List, n)
	visited = make([]bool, n)
	for i := 0; i < n; i++ {
		graph[i] = list.New()
	}

	makeGraph(sc, m)
	answer(sc)
}

func makeGraph(sc *bufio.Scanner, m int) {
	for i := 0; i < m; i++ {
		s, t := nextInt(sc), nextInt(sc)
		graph[s].PushBack(t)
		graph[t].PushBack(s)
	}
}

func answer(sc *bufio.Scanner) {
	q := nextInt(sc)
	for i := 0; i < q; i++ {
		s, t := nextInt(sc), nextInt(sc)
		if dfs(s, t) {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

func dfs(idx, t int) bool {
	list := graph[idx]
	for v := list.Front(); v != nil; v = v.Next() {
		nextIdx := v.Value.(int)
		if visited[nextIdx] {
			continue
		}
		visited[nextIdx] = true

		if t == nextIdx {
			return true
		}
		if dfs(nextIdx, t) {
			return true
		}
	}

	return false
}
