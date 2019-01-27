package main

import (
	"fmt"
	"time"
)

func printNumber2(w chan bool) {
	for i := 0; i < 10; i++ {
		time.Sleep(1 * time.Microsecond)
		fmt.Printf("%d ", i)
	}
	w <- true
}

func printLetters2(w chan bool) {
	for i := 'A'; i < 'A'+10; i++ {
		time.Sleep(1 * time.Microsecond)
		fmt.Printf("%c ", i)
	}
	w <- true
}

func main() {
	w1, w2 := make(chan bool), make(chan bool)
	go printNumber2(w1)
	go printLetters2(w2)
	<-w1
	<-w2
}
