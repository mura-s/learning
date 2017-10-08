package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"

	"github.com/mura-s/learning/golang-exercise/pro_con_algo_book/common"
)

// Point 頂点
type Point struct {
	x float64
	y float64
}

const rad = math.Pi * 60.0 / 180.0

var (
	n  int
	p1 = Point{0.0, 0.0}
	p2 = Point{100.0, 0.0}
)

func main() {
	parse()

	print(p1)
	solve(n, p1, p2)
	print(p2)
}

func parse() {
	sc := bufio.NewScanner(os.Stdin)
	n, _ = strconv.Atoi(common.NextLine(sc))
}

func print(p Point) {
	fmt.Printf("%f %f\n", p.x, p.y)
}

func solve(idx int, a, b Point) {
	if idx == 0 {
		return
	}

	var s, t, u Point
	s.x = (2.0*a.x + 1.0*b.x) / 3.0
	s.y = (2.0*a.y + 1.0*b.y) / 3.0
	t.x = (1.0*a.x + 2.0*b.x) / 3.0
	t.y = (1.0*a.y + 2.0*b.y) / 3.0
	u.x = (t.x-s.x)*math.Cos(rad) - (t.y-s.y)*math.Sin(rad) + s.x
	u.y = (t.x-s.x)*math.Sin(rad) + (t.y-s.y)*math.Cos(rad) + s.y

	solve(idx-1, a, s)
	print(s)
	solve(idx-1, s, u)
	print(u)
	solve(idx-1, u, t)
	print(t)
	solve(idx-1, t, b)
}
