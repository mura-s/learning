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
2 7
EOS
)"
try "4" "$input1"

# sample2
input2="$(cat << EOS
1 1
EOS
)"
try "0" "$input2"

# sample3
input3="$(cat << EOS
50 4321098765432109
EOS
)"
try "2160549382716056" "$input3"

echo "test.sh: ok"
