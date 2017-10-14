package main

import (
	"fmt"
	"net/http"
	_ "net/http/pprof"
)

func main() {
	http.HandleFunc("/", helloHandler)
	http.ListenAndServe(":8080", nil)
}

func helloHandler(w http.ResponseWriter, r *http.Request) {
	sum := 0
	for i := 0; i < 10000; i++ {
		sum += i
	}
	fmt.Fprintf(w, "hello, world %d", sum)
}
