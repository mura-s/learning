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
3 4 6
EOS
)"
expected1="$(cat << EOS
10
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
5
7 46 11 20 11
EOS
)"
expected2="$(cat << EOS
90
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
7
994 518 941 851 647 2 581
EOS
)"
expected3="$(cat << EOS
4527
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
