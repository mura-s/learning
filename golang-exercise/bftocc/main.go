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
	tokens, err := tokenizer.Tokenize(string(input))
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(tokens)
}
