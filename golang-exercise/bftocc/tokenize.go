package main

import "fmt"

type Token rune

func (t Token) String() string {
	return string(t)
}

const (
	Add       = Token('+')
	Sub       = Token('-')
	Right     = Token('>')
	Left      = Token('<')
	Read      = Token(',')
	Write     = Token('.')
	BeginLoop = Token('[')
	EndLoop   = Token(']')
)

type Tokenizer struct{}

func (t *Tokenizer) Tokenize(input string) ([]Token, error) {
	tokens := make([]Token, 0)

	for i, c := range input {
		switch Token(c) {
		case Add, Sub, Right, Left, Read, Write, BeginLoop, EndLoop:
			tokens = append(tokens, Token(c))
		case ' ', '\n':
			// do nothing
		default:
			return nil, fmt.Errorf("invalid input, index: %d, char: %c", i, c)
		}
	}

	return tokens, nil
}
