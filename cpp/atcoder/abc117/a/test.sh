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
8 3
EOS
)"
try "2.6666666667" "$input1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
99 1
EOS
)"
try "99.0000000000" "$input2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
1 100
EOS
)"
try "0.0100000000" "$input3"
echo "sample3 ok"

echo "ok"
