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
2 2 5
1 3
1 2 2
2 1 1
EOS
)"
expected1="$(cat << EOS
6
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
2 2 3
1 3
1 2 2
2 1 1
EOS
)"
expected2="$(cat << EOS
3
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
8 15 120
1 2 6 16 1 3 11 9
1 8 1
7 3 14
8 2 13
3 5 4
5 7 5
6 4 1
6 8 17
7 8 5
1 4 2
4 7 1
6 1 3
3 1 10
2 6 5
2 4 12
5 1 30
EOS
)"
expected3="$(cat << EOS
1488
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
