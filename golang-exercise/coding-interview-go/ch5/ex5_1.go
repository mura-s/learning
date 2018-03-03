package ch5

func UpdateBits(n, m, i, j int) int {
	left := ^0 << uint(j+1)
	right := (1 << uint(i)) - 1
	mask := left | right

	n_masked := n & mask
	m_shifted := m << uint(i)

	return n_masked | m_shifted
}
