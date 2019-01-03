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
2
2
100
EOS
)"
try "2" "$input1"

# sample2
input2="$(cat << EOS
5
1
0
150
EOS
)"
try "0" "$input2"

# sample3
input3="$(cat << EOS
30
40
50
6000
EOS
)"
try "213" "$input3"

echo "test.sh: ok"
