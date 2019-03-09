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
3 70
7 60
1 80
4 50
EOS
)"
expected1="$(cat << EOS
4
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4 3
1 1000
2 4
3 1000
4 500
EOS
)"
expected2="$(cat << EOS
TLE
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
5 9
25 8
5 9
4 10
1000 1000
6 1
EOS
)"
expected3="$(cat << EOS
5
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
