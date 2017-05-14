package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// fp, _ := os.Open(os.Args[1])
	// scanner := bufio.NewScanner(fp)
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	a, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ := strconv.Atoi(scanner.Text())

	fmt.Println(a + b)
}
