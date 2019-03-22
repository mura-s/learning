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
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7
EOS
)"
expected1="$(cat << EOS
0 1 3 4
INF 0 2 3
INF INF 0 1
INF INF 7 0
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4 6
0 1 1
0 2 -5
1 2 2
1 3 4
2 3 1
3 2 7
EOS
)"
expected2="$(cat << EOS
0 1 -5 -4
INF 0 2 3
INF INF 0 1
INF INF 7 0
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 -7
EOS
)"
expected3="$(cat << EOS
NEGATIVE CYCLE
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
