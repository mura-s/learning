package ch2

// xより小さい要素を前に来るようにする
func MoveSmallerNode(n *Node, x int) *Node {
	var smallerStart, smallerEnd, biggerStart, biggerEnd *Node

	for ; n != nil; n = n.Next {
		if n.Item < x {
			if smallerStart == nil {
				smallerStart = n
				smallerEnd = smallerStart
			} else {
				smallerEnd.Next = n
				smallerEnd = n
			}
		} else {
			if biggerStart == nil {
				biggerStart = n
				biggerEnd = biggerStart
			} else {
				biggerEnd.Next = n
				biggerEnd = n
			}
		}
	}

	if smallerStart == nil {
		return biggerStart
	}

	smallerEnd.Next = biggerStart
	return smallerStart
}
