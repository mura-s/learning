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
abcbdab
bdcaba
abc
abc
abc
bc
EOS
)"
expected1="$(cat << EOS
4
3
2
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

echo "ok"
