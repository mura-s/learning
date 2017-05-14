package main

import (
	"fmt"
	"io/ioutil"
	"log"
)

func main() {
	hello := []byte("hello")
	err := ioutil.WriteFile("./file.txt", hello, 0666)
	if err != nil {
		log.Fatal(err)
	}

	message, err := ioutil.ReadFile("./file.txt")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(string(message))
}
