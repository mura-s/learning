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
TODO: input1
EOS
)"
try "TODO: expected1" "$input1"

# sample2
input2="$(cat << EOS
TODO: input2
EOS
)"
try "TODO: expected2" "$input2"

# sample3
input3="$(cat << EOS
TODO: input3
EOS
)"
try "TODO: expected3" "$input3"

echo "test.sh: ok"
