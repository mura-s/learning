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
2 3 4
100
600
400
900
1000
150
2000
899
799
EOS
)"
expected1="$(cat << EOS
350
1400
301
399
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
1 1 3
1
10000000000
2
9999999999
5000000000
EOS
)"
expected2="$(cat << EOS
10000000000
10000000000
14999999998
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS

EOS
)"
expected3="$(cat << EOS

EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
