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
3
1 5
3 9
7 8
EOS
)"
expected1="$(cat << EOS
3
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
6
8 3
4 9
12 19
18 1
13 5
7 6
EOS
)"
expected2="$(cat << EOS
8
EOS
)"
try "$input2" "$expected2"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
