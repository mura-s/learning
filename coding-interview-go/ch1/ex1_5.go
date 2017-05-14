package ch1

import (
	"bytes"
	"fmt"
)

// 文字の連続する数を使って文字列圧縮をする。
func CompressString(str string) string {
	var buf bytes.Buffer
	b, l := str[0], 1

	for i := 1; i < len(str); i++ {
		if b == str[i] {
			l++
		} else {
			buf.WriteString(fmt.Sprintf("%c%d", b, l))
			b, l = str[i], 1
		}
	}
	buf.WriteString(fmt.Sprintf("%c%d", b, l))

	if len(buf.String()) < len(str) {
		return buf.String()
	} else {
		return str
	}
}
