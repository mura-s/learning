package ch2

// 末尾から数えてk番目の要素を見つける
func DetectNode(n *Node, k int) *Node {
	target := n
	for i := 1; n != nil; i, n = i+1, n.Next {
		if i > k {
			target = target.Next
		}
	}
	return target
}
