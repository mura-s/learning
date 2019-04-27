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
3 2
1 7 2
7 8 1
8 12 1
EOS
)"
expected1="$(cat << EOS
2
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
3 4
1 3 2
3 4 4
1 4 3
EOS
)"
expected2="$(cat << EOS
3
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
9 4
56 60 4
33 37 2
89 90 3
32 43 1
67 68 3
49 51 3
31 32 3
70 71 1
11 12 3
EOS
)"
expected3="$(cat << EOS
2
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
