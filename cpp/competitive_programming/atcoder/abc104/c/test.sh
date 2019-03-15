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
2 700
3 500
5 800
EOS
)"
expected1="$(cat << EOS
3
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
2 2000
3 500
5 800
EOS
)"
expected2="$(cat << EOS
7
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
2 400
3 500
5 800
EOS
)"
expected3="$(cat << EOS
2
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

# sample4
input4="$(cat << EOS
5 25000
20 1000
40 1000
50 1000
30 1000
1 1000
EOS
)"
expected4="$(cat << EOS
66
EOS
)"
try "$input4" "$expected4"
echo "sample4 ok"

echo "ok"
