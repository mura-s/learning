package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	sc = bufio.NewScanner(os.Stdin)
	n  string
)

func parseInput() {
	sc.Scan()
	n = sc.Text()
}

func calc() {
	result, e := strconv.Atoi(n)
	if e != nil {
		panic(e)
	}

	for _, ch := range strings.Split(n, "") {
		val, e := strconv.Atoi(ch)
		if e != nil {
			panic(e)
		}
		result += val
	}

	fmt.Println(result)
}

func main() {
	parseInput()
	calc()
}
