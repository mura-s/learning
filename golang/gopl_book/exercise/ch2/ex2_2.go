package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"

	"github.com/mura-s/learning/golang-exercise/gopl_book/exercise/ch2/tempconv"
)

func main() {
	for _, arg := range getArgs() {
		t, err := strconv.ParseFloat(arg, 64)
		if err != nil {
			fmt.Fprintf(os.Stderr, "cf: %v\n", err)
			os.Exit(1)
		}
		f := tempconv.Fahrenheit(t)
		c := tempconv.Celsius(t)
		fmt.Printf("%s = %s, %s = %s\n",
			f, tempconv.FToC(f), c, tempconv.CToF(c))
	}
}

func getArgs() []string {
	var args []string
	if len(os.Args) == 1 {
		sc := bufio.NewScanner(os.Stdin)
		for sc.Scan() {
			for _, arg := range strings.Split(sc.Text(), " ") {
				args = append(args, arg)
			}
		}
	} else {
		args = os.Args[1:]
	}
	return args
}
