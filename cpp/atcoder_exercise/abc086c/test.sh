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
2
3 1 2
6 1 1
EOS
)"
try "Yes" "$input1"

# sample2
input2="$(cat << EOS
1
2 100 100
EOS
)"
try "No" "$input2"

# sample3
input3="$(cat << EOS
2
5 1 1
100 1 1
EOS
)"
try "No" "$input3"

echo "test.sh: ok"
