package ch5

func DrawHorizontalLine(
	screen []byte, width, x1, x2, y int) []byte {
	startOffset := width / 8 * y

	for i, bit := 0, byte(128); i < width; i++ {
		offset := startOffset + i/8

		if x1 <= i && i <= x2 {
			screen[offset] |= bit
		}

		if bit >>= 1; bit == 0 {
			bit = byte(128)
		}
	}

	return screen
}
