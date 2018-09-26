package main

import (
	"fmt"
	"time"
)

func main() {
	ch := make(chan bool, 10)

	go func() {
		for i := 0; i < 10; i++ {
			ch <- true
		}
		close(ch)
	}()

	for {
		v, ok := <-ch
		// chから値がなくなったらokがfalseになる
		if !ok {
			break
		}
		fmt.Println(v)
		time.Sleep(1 * time.Second)
	}

	fmt.Println("done")
}
