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
5
2 2 3 5 5
EOS
)"
expected1="$(cat << EOS
2
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
9
1 2 3 4 5 6 7 8 9
EOS
)"
expected2="$(cat << EOS
0
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
6
6 5 4 3 2 1
EOS
)"
expected3="$(cat << EOS
18
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

# sample4
input4="$(cat << EOS
7
1 1 1 1 2 3 4
EOS
)"
expected4="$(cat << EOS
6
EOS
)"
try "$input4" "$expected4"
echo "sample4 ok"

echo "ok"
