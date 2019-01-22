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
2
3 1
EOS
)"
try "2" "$input1"

# sample2
input2="$(cat << EOS
3
2 7 4
EOS
)"
try "5" "$input2"

# sample3
input3="$(cat << EOS
4
20 18 2 18
EOS
)"
try "18" "$input3"

echo "test.sh: ok"
