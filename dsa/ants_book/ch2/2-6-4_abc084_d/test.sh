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
1
3 7
EOS
)"
expected1="$(cat << EOS
2
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4
13 13
7 11
7 11
2017 2017
EOS
)"
expected2="$(cat << EOS
1
0
0
1
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
6
1 53
13 91
37 55
19 51
73 91
13 49
EOS
)"
expected3="$(cat << EOS
4
4
1
1
1
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
