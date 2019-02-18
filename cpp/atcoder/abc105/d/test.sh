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
3 2
4 1 5
EOS
)"
expected1="$(cat << EOS
3
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
13 17
29 7 5 7 9 51 7 13 8 55 42 9 81
EOS
)"
expected2="$(cat << EOS
6
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
10 400000000
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
EOS
)"
expected3="$(cat << EOS
25
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
