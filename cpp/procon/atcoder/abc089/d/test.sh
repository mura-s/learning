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
3 3 2
1 4 3
2 5 7
8 9 6
1
4 8
EOS
)"
expected1="$(cat << EOS
5
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4 2 3
3 7
1 4
5 2
6 8
2
2 2
2 2
EOS
)"
expected2="$(cat << EOS
0
0
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
5 5 4
13 25 7 15 17
16 22 20 2 9
14 11 12 1 19
10 6 23 8 18
3 21 5 24 4
3
13 13
2 10
13 13
EOS
)"
expected3="$(cat << EOS
0
5
0
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
