package main

import "fmt"

// MyStr my string
type MyStr string

const (
	a = MyStr("a")
	b = MyStr("b")
	c = MyStr("c")
)

// lintやvetでwarningにならない
func main() {
	s := MyStr("a")
	switch s {
	case a:
		fmt.Println(a)
	case b:
		fmt.Println(b)
	default:
		fmt.Println("default")
	}
}
