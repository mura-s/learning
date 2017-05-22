package main

import (
	"bufio"
	"fmt"
	"os"
)

type mapValue struct {
	count     int
	filenames map[string]struct{}
}

func main() {
	counts := make(map[string]mapValue)
	files := os.Args[1:]
	if len(files) == 0 {
		countLines(os.Stdin, "Stdin", counts)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup2: %v\n", err)
				continue
			}
			countLines(f, arg, counts)
			f.Close()
		}
	}
	for line, v := range counts {
		if v.count > 1 {
			joinedName, sep := "", ""
			for k := range v.filenames {
				joinedName += sep + k
				sep = ","
			}
			fmt.Printf("%d\t%s\n", v.count, line)
			fmt.Printf("%s\n", joinedName)
			fmt.Println("")
		}
	}
}

func countLines(f *os.File, filename string, counts map[string]mapValue) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		text := input.Text()
		count := counts[text].count + 1

		var names map[string]struct{}
		if count == 1 {
			names = make(map[string]struct{})
		} else {
			names = counts[text].filenames
		}
		names[filename] = struct{}{}

		v := mapValue{count, names}
		counts[text] = v
	}
}
