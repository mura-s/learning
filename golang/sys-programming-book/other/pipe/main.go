package main

import (
	"io"
	"os"
	"strings"
)

var (
	computer    = strings.NewReader("COMPUTER")
	system      = strings.NewReader("SYSTEM")
	programming = strings.NewReader("PROGRAMMING")
)

func main() {
	var stream io.Reader

	charA := io.NewSectionReader(programming, 5, 1)
	charS := io.NewSectionReader(system, 0, 1)
	charC := io.NewSectionReader(computer, 0, 1)
	charI, pw := io.Pipe()
	w := io.MultiWriter(pw, pw)
	go func() {
		io.Copy(w, io.NewSectionReader(programming, 8, 1))
		pw.Close()
	}()
	stream = io.MultiReader(charA, charS, charC, charI)
	io.Copy(os.Stdout, stream)
}
