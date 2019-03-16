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
echo "start"

# sample1
input1="$(cat << EOS
4
2 3 5
2 1 5
1 2 5
3 2 5
EOS
)"
try "2 2 6" "$input1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
2
0 0 100
1 1 98
EOS
)"
try "0 0 100" "$input2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
3
99 1 191
100 1 192
99 0 192
EOS
)"
try "100 0 193" "$input3"
echo "sample3 ok"

echo "ok"
