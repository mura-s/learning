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
3
1 1
2 4
4 3
EOS
)"
expected1="$(cat << EOS
3.605551
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
10
1 8
4 0
3 7
2 4
5 9
9 1
6 2
0 2
8 6
7 8
EOS
)"
expected2="$(cat << EOS
10.630146
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
4
0 0
0 100
100 0
100 100
EOS
)"
expected3="$(cat << EOS
141.421356
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

# sample4
input4="$(cat << EOS
5
3 0
1 0
0 0
4 0
2 0
EOS
)"
expected4="$(cat << EOS
4.000000
EOS
)"
try "$input4" "$expected4"
echo "sample4 ok"

# sample5
input5="$(cat << EOS
4
2 2
0 0
1 1
3 3
EOS
)"
expected5="$(cat << EOS
4.242641
EOS
)"
try "$input5" "$expected5"
echo "sample5 ok"

echo "ok"
