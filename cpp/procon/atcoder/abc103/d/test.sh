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
5 2
1 4
2 5
EOS
)"
expected1="$(cat << EOS
1
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
9 5
1 8
2 7
3 5
4 6
7 9
EOS
)"
expected2="$(cat << EOS
2
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
5 10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
EOS
)"
expected3="$(cat << EOS
4
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
