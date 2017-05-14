package ch3

// 2つのスタックを使ってキューを作る
type MyQueue struct {
	inStack  *Stack
	outStack *Stack
}

func NewMyQueue() *MyQueue {
	return &MyQueue{&Stack{}, &Stack{}}
}

func (q *MyQueue) Enqueue(val int) {
	q.inStack.Push(val)
}

func (q *MyQueue) Dequeue() int {
	if len(q.inStack.buf) == 0 && len(q.outStack.buf) == 0 {
		panic("no elements")
	}

	if len(q.outStack.buf) == 0 {
		for len(q.inStack.buf) != 0 {
			q.outStack.Push(q.inStack.Pop())
		}
	}

	return q.outStack.Pop()
}
