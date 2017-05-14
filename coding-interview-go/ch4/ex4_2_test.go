package ch4

import (
	"testing"
)

func TestSearch(t *testing.T) {
	start, end := createGraph()
	if !Search(start, end) {
		t.Errorf("Route doesn't exist")
	}

	start2, end2 := createGraph2()
	if Search(start2, end2) {
		t.Errorf("Route exist")
	}
}

func createGraph() (start, end *Node) {
	end = &Node{5, nil, Unvisited}
	node4 := &Node{4, []*Node{end}, Unvisited}
	node3 := &Node{3, nil, Unvisited}
	node2 := &Node{2, nil, Unvisited}
	start = &Node{1, []*Node{node2, node3, node4}, Unvisited}
	return
}

func createGraph2() (start, end *Node) {
	end = &Node{5, nil, Unvisited}
	node5 := &Node{5, nil, Unvisited}
	node4 := &Node{4, []*Node{node5}, Unvisited}
	node3 := &Node{3, nil, Unvisited}
	node2 := &Node{2, nil, Unvisited}
	start = &Node{1, []*Node{node2, node3, node4}, Unvisited}
	return
}
