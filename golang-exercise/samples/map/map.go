package main

import "fmt"

func main() {
	month := map[int]string{
		1: "Jan",
		2: "Feb",
	}
	delete(month, 1)
	fmt.Println(month)
}
