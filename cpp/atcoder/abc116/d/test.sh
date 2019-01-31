#!/bin/bash
try() {
    expected="$1"
    input="$2"

    actual="$(echo $input | ./main)"

    if [ "$actual" != "$expected" ]; then
        echo "$expected expected, but got $actual"
        exit 1
    fi
}

# test cases
echo "test.sh: start"

# sample1
input1="$(cat << EOS
5 3
1 9
1 7
2 6
2 5
3 1
EOS
)"
try "26" "$input1"

# sample2
input2="$(cat << EOS
7 4
1 1
2 1
3 1
4 6
4 5
4 5
4 5
EOS
)"
try "25" "$input2"

# sample3
input3="$(cat << EOS
6 5
5 1000000000
2 990000000
3 980000000
6 970000000
6 960000000
4 950000000
EOS
)"
try "4900000016" "$input3"

echo "test.sh: ok"
