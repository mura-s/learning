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
25
EOS
)"
try "Christmas" "$input1"

# sample2
input2="$(cat << EOS
22
EOS
)"
try "Christmas Eve Eve Eve" "$input2"

echo "test.sh: ok"
