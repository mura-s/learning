#!/bin/bash
all_ac=true

try() {
    input="$1"
    expected="$2"

    actual="$(echo $input | ./main)"

    if [ "$actual" != "$expected" ]; then
        echo "WA"
        echo "expected:"
        echo "$expected"
        echo
        echo "actual:"
        echo "$actual"
        echo

        all_ac=false
        return
    fi
    echo "AC"
    echo
}

# test cases
echo "[Sample1]"
input1="$(cat << EOS
5
3
2
4
3
5
EOS
)"
expected1="$(cat << EOS
7
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
10
123
123
123
123
123
EOS
)"
expected2="$(cat << EOS
5
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
10000000007
2
3
5
7
11
EOS
)"
expected3="$(cat << EOS
5000000008
EOS
)"
try "$input3" "$expected3"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
