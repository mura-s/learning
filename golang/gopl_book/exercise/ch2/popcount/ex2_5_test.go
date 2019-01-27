package popcount

import (
	"testing"
)

func TestPopCount2_5(t *testing.T) {
	if c := PopCount2_5(1000); c != 6 {
		t.Errorf("PopCount2_5 is %d, want 6", c)
	}
}

func BenchmarkPopCount2_5(b *testing.B) {
	for i := 0; i < b.N; i++ {
		PopCount2_5(0x1234567890ABCDEF)
	}
}
