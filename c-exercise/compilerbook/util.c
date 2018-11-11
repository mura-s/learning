#include "mycc.h"

// for debug tokenize
void print_tokens() {
  for (int i = 0; tokens[i].ty != TK_EOF; i++) {
    printf("%d, %d, %c\n", tokens[i].ty, tokens[i].val, *tokens[i].input);
  }
}

// for debug parse
void print_codes() {
  for (int i = 0; codes[i]; i++) {
    printf("%d:\n", i);
    printf("%d, %d, %c\n", codes[i]->ty, codes[i]->val, codes[i]->name);

    Node *lhs = codes[i]->lhs;
    if (lhs != NULL) {
      printf("lhs, %d, %d, %c\n", lhs->ty, lhs->val, lhs->name);
    }

    Node *rhs = codes[i]->rhs;
    if (rhs != NULL) {
      printf("rhs, %d, %d, %c\n", rhs->ty, rhs->val, rhs->name);
    }
  }
}