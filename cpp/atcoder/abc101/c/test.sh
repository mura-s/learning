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
4 3
2 3 1 4
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
3 3
1 2 3
EOS
)"
expected2="$(cat << EOS
1
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
8 3
7 3 1 8 4 6 2 5
EOS
)"
expected3="$(cat << EOS
4
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

# sample4
input4="$(cat << EOS
8 3
7 4 8 1 4 6 2 5
EOS
)"
expected4="$(cat << EOS
4
EOS
)"
try "$input4" "$expected4"
echo "sample4 ok"

# sample5
input5="$(cat << EOS
8 7
7 5 8 5 6 2 5 1
EOS
)"
expected5="$(cat << EOS
2
EOS
)"
try "$input5" "$expected5"
echo "sample5 ok"

echo "ok"
