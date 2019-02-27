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
apple
orange
apple
1
grape
EOS
)"
expected1="$(cat << EOS
2
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
3
apple
orange
apple
5
apple
apple
apple
apple
apple
EOS
)"
expected2="$(cat << EOS
1
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
1
voldemort
10
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
EOS
)"
expected3="$(cat << EOS
0
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

# sample4
input4="$(cat << EOS
6
red
red
blue
yellow
yellow
red
5
red
red
yellow
green
blue
EOS
)"
expected4="$(cat << EOS
1
EOS
)"
try "$input4" "$expected4"
echo "sample4 ok"

echo "ok"
