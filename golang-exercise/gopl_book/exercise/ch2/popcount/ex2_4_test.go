package popcount

import (
	"testing"
)

func TestPopCount2_4(t *testing.T) {
	if c := PopCount2_4(1000); c != 6 {
		t.Errorf("PopCount2_4 is %d, want 6", c)
	}
}

func BenchmarkPopCount2_4(b *testing.B) {
	for i := 0; i < b.N; i++ {
		PopCount2_4(0x1234567890ABCDEF)
	}
}
