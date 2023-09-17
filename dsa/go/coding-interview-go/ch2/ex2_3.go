package ch2

// 中央の要素のみアクセス可能。その要素を削除する。
func DeleteCenterNode(n *Node) {
	if n == nil || n.Next == nil {
		return
	}
	n.Item = n.Next.Item
	n.Next = n.Next.Next
}
