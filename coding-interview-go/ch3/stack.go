package ch3

// ベーシックなStack
type Stack struct {
	buf []int
}

func (stack *Stack) Push(value int) {
	stack.buf = append(stack.buf, value)
}

func (stack *Stack) Pop() int {
	value := stack.buf[len(stack.buf)-1]
	stack.buf = stack.buf[0 : len(stack.buf)-1]
	return value
}

func (stack *Stack) Peek() int {
	return stack.buf[len(stack.buf)-1]
}

func (stack *Stack) isEmpty() bool {
	return len(stack.buf) == 0
}
