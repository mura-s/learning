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
3
4980
7980
6980
EOS
)"
try "15950" "$input1"

# sample2
input2="$(cat << EOS
4
4320
4320
4320
4320
EOS
)"
try "15120" "$input2"

echo "test.sh: ok"
