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
2 3 5
EOS
)"
expected1="$(cat << EOS
7
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
10
1 1 1 1 1 1 1 1 1 1
EOS
)"
expected2="$(cat << EOS
11
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

echo "ok"
