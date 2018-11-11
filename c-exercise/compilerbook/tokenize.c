#include "mycc.h"

Token tokens[100];

static struct {
  char *name;
  int ty;
} symbols[] = {
    {"==", TK_EQ},
    {"!=", TK_NE},
    {NULL, 0},
};

void tokenize(char *p) {
  int i = 0;

loop:
  while (*p) {
    // skip whitespace
    if (isspace(*p)) {
      p++;
      continue;
    }

    // multi-letter symbol
    for (int j = 0; symbols[j].name; j++) {
      char *name = symbols[j].name;
      int len = strlen(name);
      if (strncmp(p, name, len))
        continue;

      tokens[i].ty = symbols[j].ty;
      tokens[i].input = p;
      i++;
      p += len;
      goto loop;
    }

    // single-letter token
    if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '(' ||
        *p == ')' || *p == '=' || *p == ';') {
      tokens[i].ty = *p;
      tokens[i].input = p;
      i++;
      p++;
      continue;
    }

    // number
    if (isdigit(*p)) {
      tokens[i].ty = TK_NUM;
      tokens[i].input = p;
      tokens[i].val = strtol(p, &p, 10);
      i++;
      continue;
    }

    // identifier
    if ('a' <= *p && *p <= 'z') {
      tokens[i].ty = TK_IDENT;
      tokens[i].input = p;
      i++;
      p++;
      continue;
    }

    fprintf(stderr, "トークナイズできません: '%s'\n", p);
    exit(1);
  }

  tokens[i].ty = TK_EOF;
  tokens[i].input = p;
}
