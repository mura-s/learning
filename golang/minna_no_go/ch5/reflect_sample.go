package main

import (
	"reflect"
	"fmt"
)

func main() {
	rv := reflect.ValueOf(1)
	fmt.Println(rv.Type())
	fmt.Println(rv.Kind())
	fmt.Println(rv.Interface())
}
