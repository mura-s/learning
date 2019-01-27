package popcount

import (
	"testing"
)

func TestPopCount(t *testing.T) {
	if c := PopCount(1000); c != 6 {
		t.Errorf("PopCount is %d, want 6", c)
	}
}

func TestPopCount2_3(t *testing.T) {
	if c := PopCount2_3(1000); c != 6 {
		t.Errorf("PopCount2_3 is %d, want 6", c)
	}
}

func BenchmarkPopCount(b *testing.B) {
	for i := 0; i < b.N; i++ {
		PopCount(0x1234567890ABCDEF)
	}
}

func BenchmarkPopCount2_3(b *testing.B) {
	for i := 0; i < b.N; i++ {
		PopCount2_3(0x1234567890ABCDEF)
	}
}
