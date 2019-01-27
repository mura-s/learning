#include "mycc.h"

static Vector *tokens;
static int token_pos;

static Node *compare();

static void parse_error(int i) {
  Token *t = tokens->data[i];
  fprintf(stderr, "予期せぬトークン: %d, %d, %c\n", t->ty, t->val, *t->input);
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
  Token *t1 = tokens->data[token_pos];
  if (t1->ty == TK_NUM) {
    token_pos++;
    return new_node_num(t1->val);
  }

  if (t1->ty == TK_IDENT) {
    token_pos++;
    return new_node_ident(*t1->input);
  }

  if (t1->ty == '(') {
    token_pos++;
    Node *node = compare();
    Token *t2 = tokens->data[token_pos];
    if (t2->ty != ')')
      parse_error(token_pos);

    token_pos++;
    return node;
  }

  parse_error(token_pos);
  return NULL;
}

static Node *mul() {
  Node *lhs = term();
  Token *t = tokens->data[token_pos];
  if (t->ty != '*' && t->ty != '/')
    return lhs;

  if (t->ty == '*') {
    token_pos++;
    return new_node('*', lhs, mul());
  }

  if (t->ty == '/') {
    token_pos++;
    return new_node('/', lhs, mul());
  }

  parse_error(token_pos);
  return NULL;
}

static Node *expr() {
  Node *lhs = mul();
  Token *t = tokens->data[token_pos];
  if (t->ty != '+' && t->ty != '-')
    return lhs;

  if (t->ty == '+') {
    token_pos++;
    return new_node('+', lhs, expr());
  }

  if (t->ty == '-') {
    token_pos++;
    return new_node('-', lhs, expr());
  }

  parse_error(token_pos);
  return NULL;
}

static Node *compare() {
  Node *lhs = expr();
  Token *t = tokens->data[token_pos];
  if (t->ty != TK_EQ && t->ty != TK_NE)
    return lhs;

  if (t->ty == TK_EQ) {
    token_pos++;
    return new_node(ND_EQ, lhs, expr());
  }

  if (t->ty == TK_NE) {
    token_pos++;
    return new_node(ND_NE, lhs, expr());
  }

  parse_error(token_pos);
  return NULL;
}

static Node *_assign() {
  Node *lhs = compare();
  Token *t = tokens->data[token_pos];
  if (t->ty != '=')
    return lhs;

  // t->ty == '='
  token_pos++;
  return new_node('=', lhs, _assign());
}

static Node *assign() {
  Node *node = _assign();
  Token *t = tokens->data[token_pos];
  if (t->ty != ';')
    parse_error(token_pos);

  // t->ty == ';'
  token_pos++;
  return node;
}

Vector *parse(Vector *_tokens) {
  tokens = _tokens;
  token_pos = 0;
  Vector *nodes = new_vector();

  while (((Token *)tokens->data[token_pos])->ty != TK_EOF)
    vec_push(nodes, assign());

  return nodes;
}
