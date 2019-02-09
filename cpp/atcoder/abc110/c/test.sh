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
azzel
apple
EOS
)"
expected1="$(cat << EOS
Yes
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
chokudai
redcoder
EOS
)"
expected2="$(cat << EOS
No
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
abcdefghijklmnopqrstuvwxyz
ibyhqfrekavclxjstdwgpzmonu
EOS
)"
expected3="$(cat << EOS
Yes
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
