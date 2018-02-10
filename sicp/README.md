My Solutions for the exercises in SICP.

# Setup for macOS
Install gauche.

```
$ brew install gauche
```

Install [Gauche-compat-sicp](https://github.com/shirok/Gauche-compat-sicp).

```
$ git clone git@github.com:shirok/Gauche-compat-sicp.git
$ cd Gauche-compat-sicp
$ ./configure
$ make install
```

(if needed) Install rlwrap.

```
$ brew install rlwrap
```

# Run sample code
## Gauche script
```
$ gosh sample.scm
```

## gosh prompt
```
$ rlwrap gosh

gosh> (use compat.sicp)
gosh> print true
```
