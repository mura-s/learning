package main

import "fmt"

const (
	a = iota + 1
	b
	c
)

// lintやvetでwarningにならない
func main() {
	i := 1
	switch i {
	case a:
		fmt.Println(a)
	case b:
		fmt.Println(b)
	default:
		fmt.Println("default")
	}
}
