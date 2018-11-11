#include "mycc.h"

Node *codes[100];

static int token_pos = 0;
static int code_pos = 0;

static Node *compare();

static void parseError(int i) {
  fprintf(stderr, "予期せぬトークンです: %c\n", *tokens[i].input);
  exit(1);
}

static Node *new_node(int op, Node *lhs, Node *rhs) {
  Node *node = malloc(sizeof(Node));
  node->ty = op;
  node->lhs = lhs;
  node->rhs = rhs;
  return node;
}

static Node *new_node_num(int val) {
  Node *node = malloc(sizeof(Node));
  node->ty = ND_NUM;
  node->val = val;
  return node;
}

static Node *new_node_ident(char name) {
  Node *node = malloc(sizeof(Node));
  node->ty = ND_IDENT;
  node->name = name;
  return node;
}

static Node *term() {
  if (tokens[token_pos].ty == TK_NUM)
    return new_node_num(tokens[token_pos++].val);

  if (tokens[token_pos].ty == TK_IDENT)
    return new_node_ident(*tokens[token_pos++].input);

  if (tokens[token_pos].ty == '(') {
    token_pos++;
    Node *node = compare();
    if (tokens[token_pos].ty != ')')
      parseError(token_pos);

    token_pos++;
    return node;
  }

  parseError(token_pos);
  return NULL;
}

static Node *mul() {
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

  parseError(token_pos);
  return NULL;
}

static Node *expr() {
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

  parseError(token_pos);
  return NULL;
}

static Node *compare() {
  Node *lhs = expr();
  int op = tokens[token_pos].ty;
  if (op != TK_EQ && op != TK_NE) {
    return lhs;
  }

  if (op == TK_EQ) {
    token_pos++;
    return new_node(ND_EQ, lhs, expr());
  }

  if (op == TK_NE) {
    token_pos++;
    return new_node(ND_NE, lhs, expr());
  }

  parseError(token_pos);
  return NULL;
}

static Node *_assign(Node *lhs) {
  int op = tokens[token_pos].ty;
  if (op != '=')
    return lhs;

  if (op == '=') {
    token_pos++;
    return new_node('=', lhs, _assign(compare()));
  }

  parseError(token_pos);
  return NULL;
}

static Node *assign() {
  Node *code = _assign(compare());
  int op = tokens[token_pos].ty;
  if (op != ';')
    parseError(token_pos);

  if (op == ';') {
    token_pos++;
    return code;
  }

  parseError(token_pos);
  return NULL;
}

static void _program() {
  if (tokens[token_pos].ty == TK_EOF)
    return;

  codes[code_pos] = assign();
  code_pos++;
  _program();
}

static void program() {
  codes[code_pos] = assign();
  code_pos++;
  _program();

  if (tokens[token_pos].ty != TK_EOF)
    parseError(token_pos);

  codes[code_pos] = NULL;
  return;
}

void parse() { return program(); }