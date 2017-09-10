package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"

	"github.com/mura-s/learning/golang-exercise/pro_con_algo_book/common"
)

// MaxP Pの最大値 (本当はn * wi)
const MaxP = 100000

func check(p, n, idx int, ws []int) int {
	v, sum := 0, 0
	for i := idx; i < n; i++ {
		sum += ws[i]
		if sum > p {
			break
		}
		v++
	}
	return v
}

func solve(n, k int, ws []int) int {
	for p := 1; p < MaxP; p++ {
		idx := 0
		for i := 0; i < k; i++ {
			v := check(p, n, idx, ws)
			idx += v
		}

		if idx >= n {
			return p
		}
	}

	panic("error")
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	l := strings.Split(common.NextLine(sc), " ")
	n, _ := strconv.Atoi(l[0])
	k, _ := strconv.Atoi(l[1])
	ws := make([]int, n, n)

	for i := 0; i < n; i++ {
		w, _ := strconv.Atoi(common.NextLine(sc))
		ws[i] = w
	}

	fmt.Println(solve(n, k, ws))
}
