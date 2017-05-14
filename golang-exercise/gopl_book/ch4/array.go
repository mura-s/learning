package main

import "fmt"

func zero1(ptr *[32]byte) {
	for i := range ptr {
		ptr[i] = 0
	}
}

func main() {
	b := [32]byte{1}
	zero1(&b)
	fmt.Println("%v\n", b)
}
