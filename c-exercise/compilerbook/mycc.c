#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int token_pos = 0;
Token tokens[100];

// for debug
void print_tokens() {
  for (int i = 0; tokens[i].ty != TK_EOF; i++) {
    printf("%d, %d, %c\n", tokens[i].ty, tokens[i].val, *tokens[i].input);
  }
}

void error(int i) {
  fprintf(stderr, "予期せぬトークンです: %c\n", *tokens[i].input);
  exit(1);
}

void tokenize(char *p) {
  int i = 0;
  while (*p) {
    if (isspace(*p)) {
      p++;
      continue;
    }

    if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '(' ||
        *p == ')' || *p == '=' || *p == ';') {
      tokens[i].ty = *p;
      tokens[i].input = p;
      i++;
      p++;
      continue;
    }

    if (isdigit(*p)) {
      tokens[i].ty = TK_NUM;
      tokens[i].input = p;
      tokens[i].val = strtol(p, &p, 10);
      i++;
      continue;
    }

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

Node *new_node(int op, Node *lhs, Node *rhs) {
  Node *node = malloc(sizeof(Node));
  node->ty = op;
  node->lhs = lhs;
  node->rhs = rhs;
  return node;
}

Node *new_node_num(int val) {
  Node *node = malloc(sizeof(Node));
  node->ty = ND_NUM;
  node->val = val;
  return node;
}

Node *new_node_ident(char name) {
  Node *node = malloc(sizeof(Node));
  node->ty = ND_IDENT;
  node->name = name;
  return node;
}

int code_pos = 0;
Node *codes[100];

// for debug
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

// expr()の関数プロトタイプ宣言
Node *expr();

Node *term() {
  if (tokens[token_pos].ty == TK_NUM)
    return new_node_num(tokens[token_pos++].val);

  if (tokens[token_pos].ty == TK_IDENT)
    return new_node_ident(*tokens[token_pos++].input);

  if (tokens[token_pos].ty == '(') {
    token_pos++;
    Node *node = expr();
    if (tokens[token_pos].ty != ')')
      error(token_pos);

    token_pos++;
    return node;
  }

  error(token_pos);
  return NULL;
}

Node *mul() {
  Node *lhs = term();
  int op = tokens[token_pos].ty;
  if (op != '*' && op != '/')
    return lhs;

  if (op == '*') {
    token_pos++;
    return new_node('*', lhs, mul());
  }

  if (op == '/') {
    token_pos++;
    return new_node('/', lhs, mul());
  }

  error(token_pos);
  return NULL;
}

Node *expr() {
  Node *lhs = mul();
  int op = tokens[token_pos].ty;
  if (op != '+' && op != '-')
    return lhs;

  if (op == '+') {
    token_pos++;
    return new_node('+', lhs, expr());
  }

  if (op == '-') {
    token_pos++;
    return new_node('-', lhs, expr());
  }

  error(token_pos);
  return NULL;
}

Node *_assign(Node *lhs) {
  int op = tokens[token_pos].ty;
  if (op != '=')
    return lhs;

  if (op == '=') {
    token_pos++;
    return new_node('=', lhs, _assign(expr()));
  }

  error(token_pos);
  return NULL;
}

Node *assign() {
  Node *code = _assign(expr());
  int op = tokens[token_pos].ty;
  if (op != ';')
    error(token_pos);

  if (op == ';') {
    token_pos++;
    return code;
  }

  error(token_pos);
  return NULL;
}

void _program() {
  if (tokens[token_pos].ty == TK_EOF)
    return;

  codes[code_pos] = assign();
  code_pos++;
  _program();
}

void program() {
  codes[code_pos] = assign();
  code_pos++;
  _program();

  if (tokens[token_pos].ty != TK_EOF)
    error(token_pos);

  codes[code_pos] = NULL;
  return;
}

void gen_lval(Node *node) {
  if (node->ty == ND_IDENT) {
    printf("    mov rax, rbp\n");
    printf("    sub rax, %d\n", ('z' - node->name + 1) * 8);
    printf("    push rax\n");
    return;
  }

  fprintf(stderr, "代入の左辺値が変数ではありません");
  exit(1);
}

void gen(Node *node) {
  if (node->ty == ND_NUM) {
    printf("    push %d\n", node->val);
    return;
  }

  if (node->ty == ND_IDENT) {
    gen_lval(node);
    printf("    pop rax\n");
    printf("    mov rax, [rax]\n");
    printf("    push rax\n");
    return;
  }

  if (node->ty == '=') {
    gen_lval(node->lhs);
    gen(node->rhs);

    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    mov [rax], rdi\n");
    printf("    push rdi\n");
    return;
  }

  gen(node->lhs);
  gen(node->rhs);

  printf("    pop rdi\n");
  printf("    pop rax\n");

  switch (node->ty) {
  case '+':
    printf("    add rax, rdi\n");
    break;
  case '-':
    printf("    sub rax, rdi\n");
    break;
  case '*':
    printf("    mul rdi\n");
    break;
  case '/':
    printf("    mov rdx, 0\n");
    printf("    div rdi\n");
    break;
  }

  printf("    push rax\n");
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  // tokenize & parse
  tokenize(argv[1]);
  program();

  // generate code
  printf(".intel_syntax noprefix\n");
  printf(".global _main\n");
  printf("_main:\n");

  // prologue
  printf("    push rbp\n");
  printf("    mov rbp, rsp\n");
  printf("    sub rsp, 208\n");

  for (int i = 0; codes[i]; i++) {
    gen(codes[i]);

    printf("    pop rax\n");
  }

  // epilogue
  printf("    mov rsp, rbp\n");
  printf("    pop rbp\n");
  printf("    ret\n");

  return 0;
}
