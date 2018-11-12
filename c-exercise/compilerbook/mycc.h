#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// util

typedef struct {
  void **data;
  int capacity;
  int len;
} Vector;

Vector *new_vector();
void vec_push(Vector *vec, void *elem);

typedef struct {
  Vector *keys;
  Vector *vals;
} Map;

Map *new_map();
void map_put(Map *map, char *key, void *val);
void *map_get(Map *map, char *key);

void print_tokens();
void print_nodes();

void runtest();

// tokenize

enum {
  TK_NUM = 256,
  TK_IDENT,
  TK_EQ,
  TK_NE,
  TK_EOF,
};

typedef struct {
  int ty;
  int val; // tyがTK_NUMの場合のみ使う
  char *input;
} Token;

Vector *tokenize(char *p);

// parse

enum {
  ND_NUM = 256,
  ND_IDENT,
  ND_EQ,
  ND_NE,
};

typedef struct Node {
  int ty;
  struct Node *lhs;
  struct Node *rhs;
  int val;   // tyがND_NUMの場合のみ使う
  char name; // tyがND_IDENTの場合のみ使う
} Node;

Vector *parse(Vector *_tokens);

// codegen

void gen(Node *node);
