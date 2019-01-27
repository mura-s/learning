package main

import (
	"fmt"
)

var strs = []string{
	"a1",
	"a2",
	"a3",
}

func getStringChan() <-chan string {
	ch := make(chan string)

	for _, str := range strs {
		go func(str string) {
			ch <- fmt.Sprintf("%s goroutine", str)
		}(str)
	}

	return ch
}

func main() {
	ch := getStringChan()

	for i := 0; i < len(strs); i++ {
		fmt.Println(<-ch)
	}
}
