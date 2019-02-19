#!/bin/bash
try() {
    input="$1"
    expected="$2"

    actual="$(echo $input | ./main)"

    if [ "$actual" != "$expected" ]; then
        echo "$expected expected, but got $actual"
        exit 1
    fi
}

# test cases
echo "start"

# sample1
input1="$(cat << EOS
5 3
3 1 4
1 5 9
2 6 5
3 5 8
9 7 9
EOS
)"
expected1="$(cat << EOS
56
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
5 3
1 -2 3
-4 5 -6
7 -8 -9
-10 11 -12
13 -14 15
EOS
)"
expected2="$(cat << EOS
54
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
10 5
10 -80 21
23 8 38
-94 28 11
-26 -2 18
-69 72 79
-26 -86 -54
-72 -50 59
21 65 -32
40 -94 87
-62 18 82
EOS
)"
expected3="$(cat << EOS
638
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

# sample4
input4="$(cat << EOS
3 2
2000000000 -9000000000 4000000000
7000000000 -5000000000 3000000000
6000000000 -1000000000 8000000000
EOS
)"
expected4="$(cat << EOS
30000000000
EOS
)"
try "$input4" "$expected4"
echo "sample4 ok"

echo "ok"
