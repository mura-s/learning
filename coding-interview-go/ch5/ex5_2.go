package ch5

const ERROR = "ERROR"

func PrintBinary(num float64) string {
	if num <= 0 || 1 <= num {
		return ERROR
	}

	binary := "0."
	for num > 0 {
		if len(binary) >= 32 {
			return ERROR
		}

		tmp := num * 2
		if tmp >= 1 {
			binary += "1"
			num = tmp - 1
		} else {
			binary += "0"
			num = tmp
		}
	}

	return binary
}
