package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"

	"github.com/mura-s/learning/golang-exercise/pro_con_algo_book/common"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	n, _ := strconv.Atoi(common.NextLine(sc))
	m := make(map[string]bool)

	for i := 0; i < n; i++ {
		line := strings.Split(common.NextLine(sc), " ")
		op, s := line[0], line[1]

		switch op {
		case "insert":
			m[s] = true
		case "find":
			if _, ok := m[s]; ok {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		default:
			panic(fmt.Sprintf("illegal operation: %s", op))
		}
	}
}
