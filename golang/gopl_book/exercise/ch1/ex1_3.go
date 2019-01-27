package main

import (
	"fmt"
	"os"
	"strings"
	"time"
)

func inefficientEcho() string {
	s, sep := "", ""
	for _, arg := range os.Args[1:] {
		s += sep + arg
		sep = " "
	}
	return s
}

func efficientEcho() string {
	s := strings.Join(os.Args[1:], " ")
	return s
}

func main() {
	t1 := time.Now()
	for i := 0; i < 10000000; i++ {
		_ = inefficientEcho()
	}
	fmt.Printf("inefficientEcho: %.2f sec", time.Since(t1).Seconds())

	t2 := time.Now()
	for i := 0; i < 10000000; i++ {
		_ = efficientEcho()
	}
	fmt.Printf("efficientEcho: %.2f sec", time.Since(t2).Seconds())
}
