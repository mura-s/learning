package main

import "fmt"

// go run *.go
func main() {
	shape := &Square{"hoge"}
	fmt.Println(shape.Name())
}
