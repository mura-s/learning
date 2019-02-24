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
5 100 90 80
98
40
30
21
80
EOS
)"
expected1="$(cat << EOS
23
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
8 100 90 80
100
100
90
90
90
80
80
80
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
8 1000 800 100
300
333
400
444
500
555
600
666
EOS
)"
expected3="$(cat << EOS
243
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
