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

EOS
)"
try "" "$input1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS

EOS
)"
try "" "$input2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS

EOS
)"
try "" "$input3"
echo "sample3 ok"

echo "ok"
