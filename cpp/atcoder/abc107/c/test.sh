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
5 3
-30 -10 10 20 50
EOS
)"
expected1="$(cat << EOS
40
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
3 2
10 20 30
EOS
)"
expected2="$(cat << EOS
20
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
1 1
0
EOS
)"
expected3="$(cat << EOS
0
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

# sample4
input4="$(cat << EOS
8 5
-9 -7 -4 -3 1 2 3 4
EOS
)"
expected4="$(cat << EOS
10
EOS
)"
try "$input4" "$expected4"
echo "sample4 ok"

echo "ok"
