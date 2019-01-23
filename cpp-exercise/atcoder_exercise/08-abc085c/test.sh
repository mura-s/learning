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
9 45000
EOS
)"
try "0 9 0" "$input1"

# sample2
input2="$(cat << EOS
20 196000
EOS
)"
try "-1 -1 -1" "$input2"

# sample3
input3="$(cat << EOS
1000 1234000
EOS
)"
try "2 54 944" "$input3"

# sample4
input4="$(cat << EOS
2000 20000000
EOS
)"
try "2000 0 0" "$input4"

echo "test.sh: ok"
