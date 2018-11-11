#!/bin/bash
try() {
    expected="$1"
    input="$2"

    ./mycc "$input" > tmp.s
    gcc -o tmp tmp.s
    ./tmp
    actual="$?"

    if [ "$actual" != "$expected" ]; then
        echo "$expected expected, but got $actual"
        exit 1
    fi
}

# test cases
## read a number
try 0 '0;'
try 42 '42;'

## add and sub
try 21 '5+20-4;'

## add and sub including space
try 41 ' 12 + 34 - 5; '

## four arithmetic operations
try 47 "5 + 6 * 7;"
try 15 "5*(9-6);"
try 4 "(3+5)/2;"

## 1 character local variables
try 10 "a = 6; b = 4; a + b;"
try 12 "a = b = 1; c = 3; (a + b) * c * 2;"

## == and !=
try 1 "1 == 1;"
try 0 "1 == 0;"
try 1 "0 != 1;"
try 0 "1 != 1;"
try 6 "a = 1 == 1; a+5;"
try 2 "a = (1 == 1); b = (1 != 1); a+b+1;"
try 5 'a=(1==1)+(1!=1)*2+(0!=2)*4+(4!=4);a;'

echo OK
