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
5
EOS
)"
try "YES" "$input1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
6
EOS
)"
try "NO" "$input2"
echo "sample2 ok"

echo "ok"
