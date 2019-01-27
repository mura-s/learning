package main

import "fmt"

func printNumbers1() {
	for i := 0; i < 10; i++ {
		fmt.Printf("%d ", i)
	}
}

func printLetters1() {
	for i := 'A'; i < 'A'+10; i++ {
		fmt.Printf("%c ", i)
	}
}

func goPrint1() {
	go printNumbers1()
	go printLetters1()
}

func main() {
}
