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
9
EOS
)"
try "0" "$input1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
10
EOS
)"
try "1" "$input2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
100
EOS
)"
try "543" "$input3"
echo "sample3 ok"

echo "ok"
