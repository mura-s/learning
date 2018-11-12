#include "mycc.h"

static Token *new_token(int ty, char *input) {
  Token *t = malloc(sizeof(Token));
  t->ty = ty;
  t->input = input;
  return t;
}

static struct {
  char *name;
  int ty;
} symbols[] = {
    {"==", TK_EQ},
    {"!=", TK_NE},
    {NULL, 0},
};

Vector *tokenize(char *p) {
  Vector *tokens = new_vector();

loop:
  while (*p) {
    // skip whitespace
    if (isspace(*p)) {
      p++;
      continue;
    }

    // multi-letter symbol
    for (int i = 0; symbols[i].name; i++) {
      char *name = symbols[i].name;
      int len = strlen(name);
      if (strncmp(p, name, len))
        continue;

      vec_push(tokens, new_token(symbols[i].ty, p));
      p += len;
      goto loop;
    }

    // single-letter token
    if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '(' ||
        *p == ')' || *p == '=' || *p == ';') {
      vec_push(tokens, new_token(*p, p));
      p++;
      continue;
    }

    // identifier
    if ('a' <= *p && *p <= 'z') {
      vec_push(tokens, new_token(TK_IDENT, p));
      p++;
      continue;
    }

    // number
    if (isdigit(*p)) {
      Token *t = new_token(TK_NUM, p);
      t->val = strtol(p, &p, 10);
      vec_push(tokens, t);
      continue;
    }

    fprintf(stderr, "トークナイズできません: '%s'\n", p);
    exit(1);
  }

  vec_push(tokens, new_token(TK_EOF, p));
  return tokens;
}
