#include "mycc.h"

Vector *new_vector() {
  Vector *vec = malloc(sizeof(Vector));
  vec->data = malloc(sizeof(void *) * 16);
  vec->capacity = 16;
  vec->len = 0;
  return vec;
}

void vec_push(Vector *vec, void *elem) {
  if (vec->capacity == vec->len) {
    vec->capacity *= 2;
    vec->data = realloc(vec->data, sizeof(void *) * vec->capacity);
  }
  vec->data[vec->len++] = elem;
}

Map *new_map() {
  Map *map = malloc(sizeof(Map));
  map->keys = new_vector();
  map->vals = new_vector();
  return map;
}

void map_put(Map *map, char *key, void *val) {
  vec_push(map->keys, key);
  vec_push(map->vals, val);
}

void *map_get(Map *map, char *key) {
  for (int i = map->keys->len - 1; i >= 0; i--)
    if (strcmp(map->keys->data[i], key) == 0)
      return map->vals->data[i];

  return NULL;
}

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