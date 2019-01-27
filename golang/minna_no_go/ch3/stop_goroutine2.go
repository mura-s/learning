package main

import (
	"sync"
	"fmt"
	"context"
)

var wg sync.WaitGroup

func main() {
	ctx, cancel := context.WithCancel(context.Background())
	queue := make(chan string)
	for i := 0; i < 2; i++ {
		wg.Add(1)
		go fetchURL2(ctx, queue)
	}

	queue <- "http://test.com/1"
	queue <- "http://test.com/2"
	queue <- "http://test.com/3"
	queue <- "http://test.com/4"

	cancel()
	wg.Wait()
}

func fetchURL2(ctx context.Context, queue chan string) {
	for {
		select {
		case <-ctx.Done():
			fmt.Println("worker exit")
			wg.Done()
			return
		case url := <-queue:
			fmt.Println("fetching", url)
		}
	}
}
