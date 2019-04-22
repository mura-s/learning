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
2
1 5
2 4
3 6
EOS
)"
expected1="$(cat << EOS
3
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
3
1 1 1
2 2 2
3 3 3
EOS
)"
expected2="$(cat << EOS
27
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
6
3 14 159 2 6 53
58 9 79 323 84 6
2643 383 2 79 50 288
EOS
)"
expected3="$(cat << EOS
87
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
3
1 1 1
2 2 2
2 2 3
EOS
)"
expected4="$(cat << EOS
9
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
