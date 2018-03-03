package ch1

import (
	"strings"
)

// 空白文字を%20に置き換える
func ReplaceWhiteSpace(str string) string {
	result := strings.Trim(str, " ")
	return strings.Replace(result, " ", "%20", -1)
}
