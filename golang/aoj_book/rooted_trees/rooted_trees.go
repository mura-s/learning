package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Node node
type Node struct {
	ID     int
	Parent *Node
	Childs []*Node
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)

	nodes := make([]*Node, n)
	for i := range nodes {
		nodes[i] = &Node{ID: i}
	}

	parse(sc, nodes, n)
	print(nodes)
}

func parse(sc *bufio.Scanner, nodes []*Node, n int) {
	for i := 0; i < n; i++ {
		id := nextInt(sc)
		node := nodes[id]

		k := nextInt(sc)
		childs := make([]*Node, k)
		node.Childs = childs

		for j := 0; j < k; j++ {
			childID := nextInt(sc)
			child := nodes[childID]
			childs[j] = child

			child.Parent = node
		}
	}
}

func print(nodes []*Node) {
	for _, v := range nodes {
		nodeID := v.ID

		parentID := 0
		if v.Parent == nil {
			parentID = -1
		} else {
			parentID = v.Parent.ID
		}

		depth := 0
		parent := v.Parent
		for parent != nil {
			depth++
			parent = parent.Parent
		}

		typ := ""
		if v.Parent == nil {
			typ = "root"
		} else if len(v.Childs) == 0 {
			typ = "leaf"
		} else {
			typ = "internal node"
		}

		child := "["
		for i, c := range v.Childs {
			if i != 0 {
				child += ", "
			}
			child += strconv.Itoa(c.ID)
		}
		child += "]"

		fmt.Printf("node %d: parent = %d, depth = %d, %s, %s\n",
			nodeID, parentID, depth, typ, child)
	}
}
