package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
)

func readString(filePath string) error {
	f, err := os.Open(filePath)
	if err != nil {
		return err
	}
	defer f.Close()

	reader := bufio.NewReader(f)
	for {
		buf, isPrefix, err := reader.ReadLine()
		if err != nil {
			if err != io.EOF {
				return err
			}
			break
		}

		line := string(buf)

		// 1行のデータを全て読みきれなかった場合
		if isPrefix {
			for {
				b, cont, err := reader.ReadLine()
				if err != nil {
					if err != io.EOF {
						return err
					}
					break
				}

				line += string(b)

				if !cont {
					break
				}
			}
		}
		fmt.Println(len(line))
		fmt.Println(line)
	}

	return nil
}

func main() {
	if err := readString("./in/sample.txt"); err != nil {
		log.Fatalln(err)
	}
}
