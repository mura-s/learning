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
20 4
3 7 8 4
EOS
)"
expected1="$(cat << EOS
777773
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
101 9
9 8 7 6 5 4 3 2 1
EOS
)"
expected2="$(cat << EOS
71111111111111111111111111111111111111111111111111
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
15 3
5 4 6
EOS
)"
expected3="$(cat << EOS
654
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
