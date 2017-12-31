package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
	"strconv"
)

var (
	graph       [][]int
	dup         []bool
	d           []int
	f           []int
	timeCounter int
	stack       *list.List
)

// NodeState state
type NodeState struct {
	Idx     int
	Visited bool
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
	for i := 0; i < n; i++ {
		graph[i] = make([]int, n)
	}
	dup = make([]bool, n)
	d = make([]int, n)
	f = make([]int, n)
	stack = list.New()

	makeGraph(sc, n)
	dfs(n)
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

func dfs(n int) {
	stack.PushBack(&NodeState{0, false})

	for stack.Len() != 0 {
		elem := stack.Remove(stack.Back())
		ns := elem.(*NodeState)

		// 同じNodeが複数Stackに乗っているケースを弾く
		if !ns.Visited && dup[ns.Idx] {
			continue
		}

		timeCounter++
		if ns.Visited {
			f[ns.Idx] = timeCounter
		} else {
			d[ns.Idx] = timeCounter
			dup[ns.Idx] = true
			ns.Visited = true
			stack.PushBack(ns)

			for j := n - 1; j >= 0; j-- {
				if graph[ns.Idx][j] == 1 {
					stack.PushBack(&NodeState{j, false})
				}
			}
		}
	}
}

func print(n int) {
	for i := 0; i < n; i++ {
		fmt.Printf("%d %d %d\n", i+1, d[i], f[i])
	}
}
