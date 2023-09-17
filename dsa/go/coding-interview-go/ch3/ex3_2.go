package ch3

import "math"

// 最小の要素を返すmin()を持つStack。
// push, pop, minはすべてO(1)。
type MinStack struct {
	buf []MinNode
}

type MinNode struct {
	value int
	min   int
}

func (stack *MinStack) Push(value int) {
	min := lowerInt(value, stack.Min())
	stack.buf = append(stack.buf, MinNode{value, min})
}

func (stack *MinStack) Pop() int {
	value := stack.buf[len(stack.buf)-1].value
	stack.buf = stack.buf[0 : len(stack.buf)-1]
	return value
}

func (stack *MinStack) Min() int {
	if len(stack.buf) == 0 {
		return math.MaxInt64
	} else {
		return stack.buf[len(stack.buf)-1].min
	}
}

func lowerInt(i1, i2 int) int {
	if i1 < i2 {
		return i1
	} else {
		return i2
	}
}
