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
1 7 11
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
3 81
33 105 57
EOS
)"
expected2="$(cat << EOS
24
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
1 1
1000000000
EOS
)"
expected3="$(cat << EOS
999999999
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
