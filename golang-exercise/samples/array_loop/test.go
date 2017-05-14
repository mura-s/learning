package main

import (
	"fmt"
)

func main() {
	strList := []string{
		"abc",
		"bcd",
		"xxx",
	}

	for _, s := range strList {
		fmt.Println(s)
	}
}
