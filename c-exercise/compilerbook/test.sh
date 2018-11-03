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

echo OK
