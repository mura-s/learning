package main

import (
	"bytes"
	"fmt"
	"strings"
	"text/template"
)

const clangTmpl = `#include "stdio.h"

int main()
{
	char tape[30000] = {};
	char *ptr = tape;

	{{ .Partial }}
}
`

type Generator struct {
	tmpl *template.Template
}

func NewGenerator() (*Generator, error) {
	t, err := template.New("clangTmpl").Parse(clangTmpl)
	if err != nil {
		return nil, err
	}
	return &Generator{tmpl: t}, nil
}

func (g *Generator) Generate(tokens []Token) (string, error) {
	var builder strings.Builder

	for _, t := range tokens {
		switch t {
		case Add:
			builder.WriteString("(*ptr)++;\n")
		case Sub:
			builder.WriteString("(*ptr)--;\n")
		case Right:
			builder.WriteString("ptr++;\n")
		case Left:
			builder.WriteString("ptr--;\n")
		case Read:
			builder.WriteString("*ptr=getchar();\n")
		case Write:
			builder.WriteString("putchar(*ptr);\n")
		case BeginLoop:
			builder.WriteString("while(*ptr){\n")
		case EndLoop:
			builder.WriteString("}\n")
		default:
			return "", fmt.Errorf("invalid token, %s", t)
		}
	}

	var buf bytes.Buffer
	err := g.tmpl.Execute(&buf, struct{ Partial string }{builder.String()})
	if err != nil {
		return "", err
	}
	return buf.String(), nil
}
