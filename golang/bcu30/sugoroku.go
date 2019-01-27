package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func run(n, k int, as []int) int {
	pos := 0

	for i := 0; i < k; i++ {
		tmpPos := pos + as[i]
		if tmpPos < n {
			pos += as[i]
		} else if tmpPos == n {
			pos = n
			break
		} else {
			back := as[i] - (n - pos)
			pos = n - back
		}
	}

	return pos
}

func main() {
	sc.Split(bufio.ScanWords)
	n := nextInt()
	k := nextInt()
	as := make([]int, 0, k)

	for i := 0; i < k; i++ {
		as = append(as, nextInt())
	}

	result := run(n, k, as)
	fmt.Println(result)
}
