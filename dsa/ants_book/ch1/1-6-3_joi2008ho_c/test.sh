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
4 50
3
14
15
9
EOS
)"
expected1="$(cat << EOS
48
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
3 21
16
11
2
EOS
)"
expected2="$(cat << EOS
20
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

echo "ok"
