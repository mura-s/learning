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
8
EOS
)"
try "5" "$input1"

# sample2
input2="$(cat << EOS
7
EOS
)"
try "18" "$input2"

# sample3
input3="$(cat << EOS
54
EOS
)"
try "114" "$input3"

echo "test.sh: ok"
