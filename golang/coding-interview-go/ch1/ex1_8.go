package ch1

import "strings"

// s2がs1を回転させたものかどうか
func IsRotateString(s1, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}

	return strings.Contains(s1+s1, s2)
}
