#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tokenize

enum {
  TK_NUM = 256,
  TK_IDENT,
  TK_EOF,
};

typedef struct {
  int ty;
  int val;
  char *input;
} Token;

extern Token tokens[100];

void tokenize(char *p);

// parse

enum {
  ND_NUM = 256,
  ND_IDENT,
};

typedef struct Node {
  int ty;
  struct Node *lhs;
  struct Node *rhs;
  int val;   // tyがND_NUMの場合のみ使う
  char name; // tyがND_IDENTの場合のみ使う
} Node;

extern Node *codes[100];

void parse();

// codegen

void gen(Node *node);

// util

void print_tokens();
void print_codes();
