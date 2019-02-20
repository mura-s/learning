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
3 8 3
0 1
3 2
6 1
EOS
)"
expected1="$(cat << EOS
1
3
0
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
4 20 9
7 2
9 1
12 1
18 1
EOS
)"
expected2="$(cat << EOS
7
18
18
1
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

echo "ok"
