package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"

	"github.com/mura-s/learning/golang-exercise/pro_con_algo_book/common"
)

var (
	n  int
	as []int
	q  int
	ms []int
)

func main() {
	parse()
	for i := 0; i < q; i++ {
		m := ms[i]
		fmt.Println(solve(0, 0, m))
	}
}

func parse() {
	sc := bufio.NewScanner(os.Stdin)
	n, _ = strconv.Atoi(common.NextLine(sc))
	l := strings.Split(common.NextLine(sc), " ")
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(l[i])
		as = append(as, a)
	}
	q, _ = strconv.Atoi(common.NextLine(sc))
	l = strings.Split(common.NextLine(sc), " ")
	for i := 0; i < q; i++ {
		m, _ := strconv.Atoi(l[i])
		ms = append(ms, m)
	}
}

func solve(idx, sum, m int) bool {
	if sum == m {
		return true
	}
	if idx == n {
		return false
	}

	b := solve(idx+1, sum, m) || solve(idx+1, sum+as[idx], m)
	return b
}
