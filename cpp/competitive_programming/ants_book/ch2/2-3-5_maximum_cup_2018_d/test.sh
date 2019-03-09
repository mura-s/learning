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
5 11 7 5
1 4 5 8 9
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
5 5 3 2
1 4 5 9 12
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
5 10 3 100
1 4 7 10 14
EOS
)"
expected3="$(cat << EOS
No
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
