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
6
1
3
5
2
4
6
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
5
5
4
3
2
1
EOS
)"
expected2="$(cat << EOS
4
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
7
1
2
3
4
5
6
7
EOS
)"
expected3="$(cat << EOS
0
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
