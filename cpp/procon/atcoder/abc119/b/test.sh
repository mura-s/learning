#!/bin/bash
try() {
    input="$1"
    expected="$2"

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
2
10000 JPY
0.10000000 BTC
EOS
)"
expected1="$(cat << EOS
48000.0
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
3
100000000 JPY
100.00000000 BTC
0.00000001 BTC
EOS
)"
expected2="$(cat << EOS
138000000.0038
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

echo "ok"
