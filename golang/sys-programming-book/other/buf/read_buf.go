package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"log"
	"os"
)

func readBuffer(filePath string) error {
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

		// line := string(buf)
		bb := bytes.NewBuffer(buf)

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

				if _, err := bb.Write(b); err != nil {
					log.Fatal(err)
				}

				if !cont {
					break
				}
			}
		}
		fmt.Println(len(bb.String()))
		fmt.Println(bb.String())
	}

	return nil
}

func main() {
	if err := readBuffer("in/sample.txt"); err != nil {
		log.Fatalln(err)
	}
}
