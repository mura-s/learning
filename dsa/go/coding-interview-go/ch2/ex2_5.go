package ch2

// 2つの連結リストで表された数を足し合わせる。
// (同じ桁の数同士のみ加算可能)
func AddTwoNode(n *Node, m *Node) *Node {
	var start, end *Node
	var carry, sum int

	for ; n != nil && m != nil; n, m = n.Next, m.Next {
		if start == nil {
			carry, sum = add(n.Item, m.Item, carry)
			start = &Node{sum, nil}
			end = start
		} else {
			carry, sum = add(n.Item, m.Item, carry)
			next := &Node{sum, nil}
			end.Next = next
			end = next
		}
	}

	if carry > 0 {
		next := &Node{carry, nil}
		end.Next = next
		end = next
	}

	return start
}

func add(i, j, k int) (carry, sum int) {
	sum = i + j + k

	if sum >= 10 {
		carry, sum = 1, sum-10
	}

	return
}
