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
?tc????
coder
EOS
)"
expected1="$(cat << EOS
atcoder
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
??p??d??
abc
EOS
)"
expected2="$(cat << EOS
UNRESTORABLE
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
a?cx???
abc
EOS
)"
expected3="$(cat << EOS
aacxabc
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
