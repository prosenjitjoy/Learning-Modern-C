#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr double PI = 3.1416;
bool is_testing = true;

[[deprecated]]
void visit(void* node_data, void* user_data) {
  (void)node_data;
  (void)user_data;
}

void counter() {
  static unsigned obj_count = 0;
  obj_count++;
  printf("Count: %d\n", obj_count);
}

[[nodiscard]]
char* mstrcat(const char* s1, const char* s2) {
  const size_t s1_len = strlen(s1);
  char* const s12 = malloc(s1_len + strlen(s2) + 1);
  strcpy(s12, s1);
  strcpy(s12 + s1_len, s2);
  return s12;
}

int main(int argc, [[maybe_unused]] char* argv[argc + 1]) {
  int x = 3;
  bool add_dx = true;
  int dx = 1;
  int r;
  r = x + (add_dx ? dx : 0);
  printf("%d\n", r);

  char msg[] = "hello";
  char* const end = msg + strlen(msg);
  char last = end[-1];
  putchar(last);

  (void)x;
  size_t pos = -1;
  printf("%lu\n", pos);

  char buf[4096];
  size_t n = sizeof buf / sizeof buf[0];
  (void)n;

  counter();
  counter();
  counter();

  (void)PI;

  [[maybe_unused]] char *s1, *s2;  // both pointer to char (error prone syntax)
  [[maybe_unused]] typeof(char*) t1, t2;  // same

  char* const message = mstrcat("hello", ", world");
  free(message);
}
