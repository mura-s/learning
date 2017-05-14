package ch2

// LinkedListから重複する要素を削除
func DeleteDuplicateNode(n *Node) {
	nodeMap := make(map[int]bool)

	cur := n
	next := n.Next
	nodeMap[cur.Item] = true

	for next != nil {
		if _, ok := nodeMap[next.Item]; ok {
			cur.Next = next.Next
		} else {
			nodeMap[next.Item] = true
		}
		cur = next
		next = next.Next
	}
}
