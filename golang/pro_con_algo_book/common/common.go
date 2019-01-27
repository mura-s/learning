package common

import "bufio"

func NextLine(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}
