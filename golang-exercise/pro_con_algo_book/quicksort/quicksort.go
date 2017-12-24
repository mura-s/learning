package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type card struct {
	suit  string
	value int
}

func nextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	n, _ := strconv.Atoi(nextLine(sc))

	a := make([]*card, n)
	for i := 0; i < n; i++ {
		line := strings.Split(nextLine(sc), " ")
		suit := line[0]
		value, _ := strconv.Atoi(line[1])
		a[i] = &card{suit, value}
	}

	quicksort(a, 0, n-1)

	for _, c := range a {
		fmt.Printf("%s %d\n", c.suit, c.value)
	}
}

func quicksort(a []*card, p, r int) {
	if p < r {
		q := partition(a, p, r)
		quicksort(a, p, q-1)
		quicksort(a, q+1, r)
	}
}

func partition(a []*card, p, r int) int {
	x := a[r]
	i := p
	for j := p; j < r; j++ {
		if a[j].value <= x.value {
			a[i], a[j] = a[j], a[i]
			i++
		}
	}
	a[i], a[r] = a[r], a[i]
	return i
}
