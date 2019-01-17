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
echo "test.sh: start"

# sample1
input1="$(cat << EOS
20 2 5
EOS
)"
try "84" "$input1"

# sample2
input2="$(cat << EOS
10 1 2
EOS
)"
try "13" "$input2"

# sample3
input3="$(cat << EOS
100 4 16
EOS
)"
try "4554" "$input3"

echo "test.sh: ok"
