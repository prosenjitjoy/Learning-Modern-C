#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_csi(size_t n, const int vals[static 10]) {
  if (n == 0) {
    return;
  }

  printf("%d", vals[0]);
  for (size_t i = 1; i < n; i++) {
    printf(", %d", vals[i]);
  }
  printf("\n");
}

void hello_world() { puts(__func__); }

inline int maxi(int a, int b) { return a > b ? a : b; }

struct c_int_fmt {
  bool cif_short : 1;
  bool cif_int : 1;
  bool cif_long : 1;
  bool cif_unsigned : 1;
  bool cif_const : 1;
  bool cif_static : 1;
};

union value {
  long i;
  double f;
  char c;
  char* s;
};

enum token_kind {
  TOKEN_NONE,
  TOKEN_INT,
  TOKEN_FLOAT,
  TOKEN_CHAR,
  TOKEN_STR,
};

struct token {
  enum token_kind kind;
  union {
    int i;
    double f;
    char c;
    char* s;
  };
};

int main(int argc, [[maybe_unused]] const char* argv[argc + 1]) {
  const int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print_csi(9, arr);

  for (int i = 0; i < argc; i++) {
    printf("%d %s\n", i, argv[i]);
  }

  hello_world();

  union value v;
  v.i = 1941;
  v.c = 'a';
  union value* pv = &v;
  pv->s = malloc(6);
  strcpy(pv->s, "hello");

  struct token t = {.kind = TOKEN_CHAR, .c = 'a'};
}
