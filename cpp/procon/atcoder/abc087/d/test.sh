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
3 3
1 2 1
2 3 1
1 3 2
EOS
)"
expected1="$(cat << EOS
Yes
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
3 3
1 2 1
2 3 1
1 3 5
EOS
)"
expected2="$(cat << EOS
No
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
4 3
2 1 1
2 3 5
3 4 2
EOS
)"
expected3="$(cat << EOS
Yes
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
10 3
8 7 100
7 9 100
9 8 100
EOS
)"
expected4="$(cat << EOS
No
EOS
)"
try "$input4" "$expected4"

echo "[Sample5]"
input5="$(cat << EOS
100 0
EOS
)"
expected5="$(cat << EOS
Yes
EOS
)"
try "$input5" "$expected5"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
