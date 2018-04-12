# bftocc
Brainf*ck to C compiler written in Go.

**bftocc** reads Brainf*ck code from STDIN, and prints C code to STDOUT.

## Build
```
make
```

## Execute
```
bin/bftocc < input/bf.txt > tmp/out.c
```

or

```
echo "your Brainf*ck code" | bin/bftocc > ${output_file}
```

## Build and Execute generated C code
```
gcc -o tmp/out tmp/out.c
tmp/out
```

# References
- [Brainf*ck](https://en.wikipedia.org/wiki/Brainfuck)
- [Brainf*ck (ja)](https://ja.wikipedia.org/wiki/Brainfuck)
- [Making a Brainf*ck to C Compiler in Rust](https://medium.com/@CanHasCommunism/making-a-brainf-ck-to-c-compiler-in-rust-10f0c01a282d)
