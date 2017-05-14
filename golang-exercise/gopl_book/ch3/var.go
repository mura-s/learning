package main

import "fmt"

var (
	a = "a"
	b = "b"
)

const (
	e  = 2.71
	pi = 3.14
)

func main() {
	fmt.Printf("%s %s\n", a, b)
	fmt.Printf("%v %v\n", e, pi)
}
