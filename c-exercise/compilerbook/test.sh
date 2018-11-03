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
try 0 0
try 42 42

echo OK
