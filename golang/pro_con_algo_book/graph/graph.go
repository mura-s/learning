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

	graph := make([][]int, n)
	for i := 0; i < n; i++ {
		graph[i] = make([]int, n)
	}
	makeGraph(sc, graph, n)

	print(graph, n)
}

func makeGraph(sc *bufio.Scanner, graph [][]int, n int) {
	for i := 0; i < n; i++ {
		u := nextInt(sc)
		k := nextInt(sc)
		for j := 0; j < k; j++ {
			v := nextInt(sc)
			graph[u-1][v-1] = 1
		}
	}
}

func print(graph [][]int, n int) {
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if j != 0 {
				fmt.Print(" ")
			}
			fmt.Print(graph[i][j])
		}
		fmt.Println("")
	}
}
