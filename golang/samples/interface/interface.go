package main

type Shape interface {
	Name() string
}

type Square struct {
	name string
}

func (s Square) Name() string {
	return s.name
}
