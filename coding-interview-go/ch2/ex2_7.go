package ch2

// 連結リストが回分になっているかどうか
func IsPalindrome(n *Node) bool {
	ary := []int{}

	for ; n != nil; n = n.Next {
		ary = append(ary, n.Item)
	}

	l := len(ary)
	for i := 0; i < l/2; i++ {
		if ary[i] != ary[l-1-i] {
			return false
		}
	}

	return true
}
