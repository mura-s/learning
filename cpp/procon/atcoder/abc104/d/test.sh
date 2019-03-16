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
A??C
EOS
)"
expected1="$(cat << EOS
8
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
ABCBC
EOS
)"
expected2="$(cat << EOS
3
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
????C?????B??????A???????
EOS
)"
expected3="$(cat << EOS
979596887
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
