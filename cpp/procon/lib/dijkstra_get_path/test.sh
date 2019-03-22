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
7 20 0
0 1 2
1 0 2
0 2 5
2 0 5
1 2 4
2 1 4
1 3 6
3 1 6
1 4 10
4 1 10
2 3 2
3 2 2
3 5 1
5 3 1
4 5 3
5 4 3
4 6 5
6 4 5
5 6 9
6 5 9
EOS
)"
expected1="$(cat << EOS
16
0 2 3 5 4 6
EOS
)"
try "$input1" "$expected1"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
