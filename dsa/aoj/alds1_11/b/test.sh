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
1 1 2
2 1 4
3 0
4 1 3
EOS
)"
expected1="$(cat << EOS
1 1 8
2 2 7
3 4 5
4 3 6

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0
EOS
)"
expected2="$(cat << EOS
1 1 12
2 2 11
3 3 8
4 9 10
5 4 7
6 5 6
EOS
)"
try "$input2" "$expected2"

# echo "[Sample4]"
# input4="$(cat << EOS
#
# EOS
# )"
# expected4="$(cat << EOS
#
# EOS
# )"
# try "$input4" "$expected4"

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
