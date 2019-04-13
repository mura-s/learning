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
5 1
00010
EOS
)"
expected1="$(cat << EOS
4
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
14 2
11101010110011
EOS
)"
expected2="$(cat << EOS
8
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
1 1
1
EOS
)"
expected3="$(cat << EOS
1
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
14 2
00010101001100
EOS
)"
expected4="$(cat << EOS
7
EOS
)"
try "$input4" "$expected4"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
