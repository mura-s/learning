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
echo "test.sh: start"

# sample1
input1="$(cat << EOS
4
10
8
8
6
EOS
)"
try "3" "$input1"

# sample2
input2="$(cat << EOS
3
15
15
15
EOS
)"
try "1" "$input2"

# sample3
input3="$(cat << EOS
7
50
30
50
100
50
80
30
EOS
)"
try "4" "$input3"

echo "test.sh: ok"
