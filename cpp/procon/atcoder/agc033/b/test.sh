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
2 3 3
2 2
RRL
LUD
EOS
)"
expected1="$(cat << EOS
YES
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4 3 5
2 2
UDRRR
LLDUD
EOS
)"
expected2="$(cat << EOS
NO
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
5 6 11
2 1
RLDRRUDDLRL
URRDRLLDLRD
EOS
)"
expected3="$(cat << EOS
NO
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
3 3 4
2 2
DRLL
RUDD
EOS
)"
expected4="$(cat << EOS
NO
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
