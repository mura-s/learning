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
erasedream
EOS
)"
try "YES" "$input1"

# sample2
input2="$(cat << EOS
dreameraser
EOS
)"
try "YES" "$input2"

# sample3
input3="$(cat << EOS
dreamerer
EOS
)"
try "NO" "$input3"

echo "test.sh: ok"
