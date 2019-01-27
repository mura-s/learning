package ch2

// 循環する部分の最初のノードを返す
func DetectCirculationNode(n *Node) *Node {
	start := n

	for i := 0; n != nil; i, n = i+1, n.Next {
		for j, tmp := 0, start; j != i; j, tmp = j+1, tmp.Next {
			if n.Item == tmp.Item && n.Next == tmp.Next {
				return n
			}
		}
	}

	return nil
}
