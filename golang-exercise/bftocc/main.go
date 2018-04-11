package main

import (
	"fmt"
	"log"
)

func main() {
	input := "+-><,.[]>+-,.."

	tokenizer := &Tokenizer{}
	tokens, err := tokenizer.Tokenize(input)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(tokens)
}
