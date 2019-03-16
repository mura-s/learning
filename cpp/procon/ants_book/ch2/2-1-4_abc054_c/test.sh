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
3 3
1 2
1 3
2 3
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
7 7
1 3
2 7
3 4
4 5
4 6
5 6
6 7
EOS
)"
expected2="$(cat << EOS
1
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

echo "ok"
