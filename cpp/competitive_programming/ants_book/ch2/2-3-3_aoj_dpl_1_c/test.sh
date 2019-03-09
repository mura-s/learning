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
4 8
4 2
5 2
2 1
8 3
EOS
)"
expected1="$(cat << EOS
21
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
2 20
5 9
4 10
EOS
)"
expected2="$(cat << EOS
10
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
3 9
2 1
3 1
5 2
EOS
)"
expected3="$(cat << EOS
27
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
