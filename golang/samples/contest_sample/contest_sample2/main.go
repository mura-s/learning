package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	sc     = bufio.NewScanner(os.Stdin)
	n      int
	ts     []int
	ss     []float64
	hWater float64
	coffee float64
)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func nextFloat() float64 {
	sc.Scan()
	i, e := strconv.ParseFloat(sc.Text(), 64)
	if e != nil {
		panic(e)
	}
	return i
}

func parseInput() {
	sc.Split(bufio.ScanWords)

	n = nextInt()
	for i := 0; i < n; i++ {
		ts = append(ts, nextInt())
		ss = append(ss, nextFloat())
	}
}

func operate(idx int) {
	switch ts[idx] {
	case 1:
		hWater += ss[idx]
	case 2:
		coffee += ss[idx]
	case 3:
		tmpWater := hWater
		hWater -= ss[idx] * hWater / (hWater + coffee)
		coffee -= ss[idx] * coffee / (tmpWater + coffee)
	default:
		panic("unexpected value")
	}
}

func printResult() {
	concentration := coffee / (hWater + coffee) * 100
	fmt.Println(int(concentration))
}

func main() {
	parseInput()

	for i := 0; i < n; i++ {
		operate(i)
	}

	printResult()
}
