package main

import (
	"fmt"

	"github.com/rs/xid"
)

func main() {
	// idを生成
	guid := xid.New()
	fmt.Println(guid.String())

	// binaryの各partの情報
	machine := guid.Machine()
	pid := guid.Pid()
	time := guid.Time()
	counter := guid.Counter()
	fmt.Printf("machine: %v, pid: %v, time: %v, counter: %v\n", machine, pid, time, counter)

	// 文字列表現からIDに戻す
	id, err := xid.FromString("b8hpcg8hv3amvi9dol0g")
	if err != nil {
		panic(err)
	}
	fmt.Println(id)
}
