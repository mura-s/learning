package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

func main() {
	input, err := ioutil.ReadAll(os.Stdin)
	if err != nil {
		log.Fatal(err)
	}

	tokenizer := &Tokenizer{}
	tokens := tokenizer.Tokenize(string(input))
	fmt.Println(tokens)
}
