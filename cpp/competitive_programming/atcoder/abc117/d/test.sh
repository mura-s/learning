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
3 7
1 6 3
EOS
)"
try "14" "$input1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
4 9
7 4 0 3
EOS
)"
try "46" "$input2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
1 0
1000000000000
EOS
)"
try "1000000000000" "$input3"
echo "sample3 ok"

echo "ok"
