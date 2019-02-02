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
5 3
10
15
11
14
12
EOS
)"
try "2" "$input1"

# sample2
input2="$(cat << EOS
5 3
5
7
5
7
7
EOS
)"
try "0" "$input2"

echo "test.sh: ok"
