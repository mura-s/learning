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
2 5
10 12 1 2 14
EOS
)"
try "5" "$input1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
3 7
-10 -3 0 9 -100 2 17
EOS
)"
try "19" "$input2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
100 1
-100000
EOS
)"
try "0" "$input3"
echo "sample3 ok"

echo "ok"
