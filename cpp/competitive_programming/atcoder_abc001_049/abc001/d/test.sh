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
4
1148-1210
1323-1401
1106-1123
1129-1203
EOS
)"
expected1="$(cat << EOS
1105-1210
1320-1405
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
1
0000-2400
EOS
)"
expected2="$(cat << EOS
0000-2400
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
6
1157-1306
1159-1307
1158-1259
1230-1240
1157-1306
1315-1317
EOS
)"
expected3="$(cat << EOS
1155-1310
1315-1320
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

# sample4
input4="$(cat << EOS
3
0000-0032
1159-1359
0025-0104
EOS
)"
expected4="$(cat << EOS
0000-0105
1155-1400
EOS
)"
try "$input4" "$expected4"
echo "sample4 ok"

echo "ok"
