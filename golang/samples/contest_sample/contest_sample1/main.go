package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const maxTurn = 100

var (
	sc = bufio.NewScanner(os.Stdin)
	t  []int
	d  []int
)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func parseInput() {
	sc.Split(bufio.ScanWords)

	n := nextInt()
	for i := 0; i < n; i++ {
		t = append(t, nextInt())
	}

	m := nextInt()
	for i := 0; i < m; i++ {
		d = append(d, nextInt())
	}
}

func playTurn(turn int) {
	t[0] = d[turn]
	pos := 0

	for i := 0; i < maxTurn; i++ {
		pos += t[pos]

		if pos == len(t)-1 {
			fmt.Println("Yes")
			return
		} else if pos < 0 || len(t) <= pos {
			fmt.Println("No")
			return
		} else if t[pos] == 0 {
			fmt.Println("No")
			return
		}
	}

	fmt.Println("No")
}

func main() {
	parseInput()

	for i := 0; i < len(d); i++ {
		playTurn(i)
	}
}
