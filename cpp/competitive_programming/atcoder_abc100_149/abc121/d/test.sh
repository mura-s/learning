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

EOS
)"
expected1="$(cat << EOS

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS

EOS
)"
expected2="$(cat << EOS

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS

EOS
)"
expected3="$(cat << EOS

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
