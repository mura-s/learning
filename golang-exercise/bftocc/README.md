# bftocc
Brainf*ck to C compiler written in Go.

## Build
```
make
```

## Execute
```
bin/bftocc < input/bf.txt > tmp/out.c
```

## Build and Execute generated C code
```
gcc -o tmp/out tmp/out.c
tmp/out
```

