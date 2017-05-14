package main

import (
	"sync"
	"fmt"
)

var wg sync.WaitGroup

func main() {
	queue := make(chan string)
	for i := 0; i < 2; i++ {
		wg.Add(1)
		go fetchURL(queue)
	}

	queue <- "http://test.com/1"
	queue <- "http://test.com/2"
	queue <- "http://test.com/3"
	queue <- "http://test.com/4"

	close(queue)
	wg.Wait()
}

func fetchURL(queue chan string) {
	for {
		url, more := <-queue
		if more {
			fmt.Println("fetching", url)
		} else {
			fmt.Println("worker exit")
			wg.Done()
			return
		}
	}
}
