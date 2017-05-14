package ch3

const StackSize int = 100

// bufの中に3つのStackを持つ。
// それぞれのStackは以下のindexに分割されている。
// Stack1: 0, 3, 6, ...
// Stack2: 1, 4, 7, ...
// Stack3: 2, 5, 8, ...
type ThreeStack struct {
	buf     [StackSize * 3]int
	pointer [3]int
}

func NewThreeStack() *ThreeStack {
	stack := &ThreeStack{pointer: [3]int{-1, -1, -1}}
	return stack
}

func (stack *ThreeStack) Push(value, stackNum int) {
	stack.pointer[stackNum]++
	stack.buf[stack.getStackPos(stackNum)] = value
}

func (stack *ThreeStack) Pop(stackNum int) int {
	value := stack.buf[stack.getStackPos(stackNum)]
	stack.buf[stack.getStackPos(stackNum)] = 0
	stack.pointer[stackNum]--
	return value
}

func (stack *ThreeStack) Peek(stackNum int) int {
	return stack.buf[stack.getStackPos(stackNum)]
}

func (stack *ThreeStack) getStackPos(stackNum int) int {
	return stack.pointer[stackNum]*3 + stackNum
}
