package main

import (
	"fmt"
	"io"
	"math/rand"
	"os"
	"os/exec"
	"strings"
	"time"
)

var (
	rightCmd = "./main"
	wrongCmd = "./main2"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	for {
		// 2 <= N <= 10
		N := rand.Int()%9 + 2

		A := make([]int, N)
		for i := 0; i < N; i++ {
			// 1 <= Ai << 100
			A[i] = rand.Int()%100 + 1
		}
		var b strings.Builder
		for i := 0; i < N; i++ {
			if i != 0 {
				fmt.Fprint(&b, " ")
			}
			fmt.Fprintf(&b, "%v", A[i])
		}
		input := fmt.Sprintf("%v\n%v", N, b.String())

		// right ans
		cmd1 := exec.Command(rightCmd)
		stdin1, _ := cmd1.StdinPipe()
		io.WriteString(stdin1, input)
		stdin1.Close()
		ansByte1, _ := cmd1.Output()
		ans1 := string(ansByte1)

		// wrong ans
		cmd2 := exec.Command(wrongCmd)
		stdin2, _ := cmd2.StdinPipe()
		io.WriteString(stdin2, input)
		stdin2.Close()
		ansByte2, _ := cmd2.Output()
		ans2 := string(ansByte2)

		if ans1 != ans2 {
			fmt.Println(input)
			fmt.Printf("right: %v", ans1)
			fmt.Printf("wrong: %v", ans2)
			os.Exit(1)
		}
	}
}
