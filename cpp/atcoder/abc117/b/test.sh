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
4
3 8 5 1
EOS
)"
try "Yes" "$input1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
4
3 8 4 1
EOS
)"
try "No" "$input2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
10
1 8 10 5 8 12 34 100 11 3
EOS
)"
try "No" "$input3"
echo "sample3 ok"

echo "ok"
