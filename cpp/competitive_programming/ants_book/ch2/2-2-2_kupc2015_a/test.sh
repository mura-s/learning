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
3
higashikyoto
kupconsitetokyotokyoto
goodluckandhavefun
EOS
)"
expected1="$(cat << EOS
1
2
0
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

echo "ok"
