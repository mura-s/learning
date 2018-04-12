package main

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

func (t *Tokenizer) Tokenize(input string) []Token {
	tokens := make([]Token, 0)

	for _, c := range input {
		switch Token(c) {
		case Add, Sub, Right, Left, Read, Write, BeginLoop, EndLoop:
			tokens = append(tokens, Token(c))
		default:
			// do nothing
		}
	}

	return tokens
}
