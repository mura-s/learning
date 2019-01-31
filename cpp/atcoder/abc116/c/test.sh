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
1 2 2 1
EOS
)"
try "2" "$input1"

# sample2
input2="$(cat << EOS
5
3 1 2 3 1
EOS
)"
try "5" "$input2"

# sample3
input3="$(cat << EOS
8
4 23 75 0 23 96 50 100
EOS
)"
try "221" "$input3"

echo "test.sh: ok"
