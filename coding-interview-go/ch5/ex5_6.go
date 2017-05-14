package ch5

func SwapOddEvenBits(num uint16) uint16 {
	return ((num & 0xaaaa) >> 1) | ((num & 0x5555) << 1)
}
