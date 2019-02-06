#!/bin/bash
try() {
    expected="$1"
    input="$2"

    actual="$(echo $input | ./main)"

    if [ "$actual" != "$expected" ]; then
        echo "$expected expected, but got $actual"
        exit 1
    fi
}

# test cases
echo "start"

# sample1
input1="$(cat << EOS
2 3
1 32
2 63
1 12
EOS
)"
out1="$(cat << EOS
000001000002
000002000001
000001000001
EOS
)"
try "$out1" "$input1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
2 3
2 55
2 77
2 99
EOS
)"
out2="$(cat << EOS
000002000001
000002000002
000002000003
EOS
)"
try "$out2" "$input2"
echo "sample2 ok"

echo "ok"
