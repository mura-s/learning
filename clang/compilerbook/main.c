#include "mycc.h"

// 生成されるアセンブリはdocker or linux上で正しく動作する。
// (mac上では動作しない。)
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  // unit test
  if (strcmp(argv[1], "-test") == 0) {
    runtest();
    return 0;
  }

  // tokenize & parse
  Vector *tokens = tokenize(argv[1]);
  Vector *nodes = parse(tokens);

  // generate code
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  // prologue
  printf("    push rbp\n");
  printf("    mov rbp, rsp\n");
  printf("    sub rsp, 208\n");

  for (int i = 0; i < nodes->len; i++) {
    gen((Node *)nodes->data[i]);

    // 式の評価結果としてスタックに一つの値が残っているはずなので、スタックが溢れないようにポップしておく
    printf("    pop rax\n");
  }

  // epilogue
  printf("    mov rsp, rbp\n");
  printf("    pop rbp\n");
  printf("    ret\n");

  return 0;
}
