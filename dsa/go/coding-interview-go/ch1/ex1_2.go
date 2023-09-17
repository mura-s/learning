package ch1

// 文字列を逆に並び替える。
func Reverse(str []byte) {
	l := len(str)
	tmp := make([]byte, l)
	copy(tmp, str)

	for i := 0; i < l; i++ {
		str[l-1-i] = tmp[i]
	}
}
