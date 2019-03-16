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
2 3 1
1 1
1 2
2 2
1 2
EOS
)"
expected1="$(cat << EOS
3
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
10 3 2
1 5
2 8
7 10
1 7
3 10
EOS
)"
expected2="$(cat << EOS
1
1
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
10 10 10
1 6
2 9
4 5
4 7
4 7
5 8
6 6
6 7
7 9
10 10
1 8
1 9
1 10
2 8
2 9
2 10
3 8
3 9
3 10
1 10
EOS
)"
expected3="$(cat << EOS
7
9
10
6
8
9
6
7
8
10
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

echo "ok"
