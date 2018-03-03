package ch4

import (
	"container/list"
)

type Node struct {
	value    int
	adjacent []*Node
	state    State
}

type State int

const (
	Unvisited State = iota
	Visited
	Visiting
)

func Search(start, end *Node) bool {
	queue := list.New()

	start.state = Visiting
	queue.PushBack(start)

	for queue.Len() != 0 {
		n := queue.Remove(queue.Front()).(*Node)
		for i := 0; i < len(n.adjacent); i++ {
			m := n.adjacent[i]
			if m.state == Unvisited {
				if m == end {
					return true
				} else {
					m.state = Visiting
					queue.PushBack(m)
				}
			}
		}
		n.state = Visited
	}

	return false
}
