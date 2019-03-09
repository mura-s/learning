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
echo "test.sh: start"

# sample1
input1="$(cat << EOS
3 4 5
EOS
)"
try "6" "$input1"

# sample2
input2="$(cat << EOS
5 12 13
EOS
)"
try "30" "$input2"

# sample3
input3="$(cat << EOS
45 28 53
EOS
)"
try "630" "$input3"

echo "test.sh: ok"
