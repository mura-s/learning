#!/bin/bash
all_ac=true

try() {
    input="$1"
    expected="$2"

    actual="$(echo $input | make run)"

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
4
1 2 2 4
2 1 4
3 0
4 1 3
EOS
)"
expected1="$(cat << EOS
1 0
2 1
3 2
4 1
EOS
)"
try "$input1" "$expected1"

echo "[Sample4]"
input4="$(cat << EOS
6
1 2 2 4
2 1 5
3 2 5 6
4 0
5 1 4
6 1 6
EOS
)"
expected4="$(cat << EOS
1 0
2 1
3 -1
4 1
5 2
6 -1
EOS
)"
try "$input4" "$expected4"

# echo "[Sample5]"
# input5="$(cat << EOS
#
# EOS
# )"
# expected5="$(cat << EOS
#
# EOS
# )"
# try "$input5" "$expected5"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
