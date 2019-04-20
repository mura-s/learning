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
1 10
3 5
EOS
)"
expected1="$(cat << EOS
3
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
2 10
3 5
2 6
EOS
)"
expected2="$(cat << EOS
2
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
4 1000000000
1 1
1 10000000
1 30000000
1 99999999
EOS
)"
expected3="$(cat << EOS
860000004
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
5 500
35 44
28 83
46 62
31 79
40 43
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
