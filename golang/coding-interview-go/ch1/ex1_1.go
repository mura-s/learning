package ch1

// 重複する文字がないかどうかを判定する。
func IsUniqueString(s string) bool {
	charMap := make(map[rune]rune)
	for _, ch := range s {
		if _, ok := charMap[ch]; ok {
			return false
		}

		charMap[ch] = ch
	}

	return true
}
