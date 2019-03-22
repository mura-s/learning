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
4 5 0
0 1 1
0 2 4
1 2 2
2 3 1
1 3 5
EOS
)"
expected1="$(cat << EOS
0
1
3
4
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4 6 1
0 1 1
0 2 4
2 0 1
1 2 2
3 1 1
3 2 5
EOS
)"
expected2="$(cat << EOS
3
0
2
INF
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
