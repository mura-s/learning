package main

import (
	"context"
	"fmt"
	"sync"
	"time"
)

func main() {
	ctx := context.Background()
	var wg sync.WaitGroup
	wg.Add(1)
	go parentProcess(ctx, &wg)
	wg.Wait()
}

func parentProcess(ctx context.Context, wg *sync.WaitGroup) {
	defer wg.Done()
	ctx, cancel := context.WithTimeout(ctx, 10*time.Second)
	defer cancel()
	wg.Add(1)
	go childProcess(ctx, wg)
	ticker := time.NewTicker(1 * time.Second)
	for {
		select {
		case t := <-ticker.C:
			fmt.Printf("parent %v\n", t)
		case <-ctx.Done():
			fmt.Println("parent done")
			return
		}
	}
}

func childProcess(ctx context.Context, wg *sync.WaitGroup) {
	defer wg.Done()
	ctx, cancel := context.WithTimeout(ctx, 5*time.Second)
	defer cancel()
	ticker := time.NewTicker(1 * time.Second)
	for {
		select {
		case t := <-ticker.C:
			fmt.Printf("child %v\n", t)
		case <-ctx.Done():
			fmt.Println("child done")
			return
		}
	}
}
