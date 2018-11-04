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
try 0 0
try 42 42

## add and sub
try 21 '5+20-4'

## add and sub including space
try 41 ' 12 + 34 - 5 '

## four arithmetic operations
try 47 "5 + 6 * 7"
try 15 "5*(9-6)"
try 4 "(3+5)/2"

echo OK
