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
yahoo
EOS
)"
expected1="$(cat << EOS
YES
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
snuke
EOS
)"
expected2="$(cat << EOS
NO
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
yyyyy
EOS
)"
expected3="$(cat << EOS
NO
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
