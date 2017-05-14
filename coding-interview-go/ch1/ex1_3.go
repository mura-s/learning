package ch1

import (
	"sort"
	"strings"
)

// 片方がもう片方の並び替えになっているか。
func IsSortedString(str1, str2 string) bool {
	if len(str1) != len(str2) {
		return false
	}

	str1Slice := strings.Split(str1, "")
	str2Slice := strings.Split(str2, "")
	sort.Strings(str1Slice)
	sort.Strings(str2Slice)

	for i := 0; i < len(str1Slice); i++ {
		if str1Slice[i] != str2Slice[i] {
			return false
		}
	}

	return true
}
