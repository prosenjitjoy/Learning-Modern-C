#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main() {
//   int c;
//   while ((c = getchar()) != EOF) {
//     putchar(c);
//   }
// }

// constexpr size_t BUF_SIZE = 4096;

// int main() {
//   char buf[BUF_SIZE];
//   size_t bytes;

//   do {
//     bytes = fread(buf, 1, BUF_SIZE, stdin);
//     if (ferror(stdin)) {
//       goto error;
//     }
//     if (fwrite(buf, 1, bytes, stdout) < bytes) {
//       goto error;
//     }
//   } while (bytes == BUF_SIZE);

//   return EXIT_SUCCESS;

// error:
//   perror("copy");
//   return EXIT_FAILURE;
// }

// constexpr size_t STRING_MIN = 4;

// int main() {
//   int c;
//   char str_buf[STRING_MIN] = {};
//   size_t str_len = 0;

//   while ((c = getchar()) != EOF) {
//     if (isprint(c)) {
//       if (str_len < STRING_MIN - 1) {
//         str_buf[str_len++] = (char)c;
//         continue;
//       }
//       if (str_len == STRING_MIN - 1) {
//         str_buf[str_len++] = '\0';
//         fputs(str_buf, stdout);
//       }
//       putchar(c);
//     } else {
//       if (str_len == STRING_MIN) {
//         putchar('\n');
//         str_len = 0;
//       }
//     }
//   }
// }

// unsigned putubin(unsigned n) {
//   if (n == 0) {
//     putchar('0');
//     return 1;
//   }

//   unsigned count = 0;
//   unsigned digits = 0;
//   for (unsigned bit = ~(~0u >> 1); bit != 0; bit >>= 1) {
//     bool const is_1 = (n & bit) != 0;
//     if (is_1 || digits > 0) {
//       putchar('0' + is_1);
//       digits++;
//     }
//     count++;
//   }

//   printf("#%u\n", count);

//   return digits;
// }

// int main() { printf("%d\n", putubin(15)); }

// void swapi(int* pa, int* pb) {
//   const int tmp = *pa;
//   *pa = *pb;
//   *pb = tmp;
// }

// int main() {
//   int* p;
//   p = nullptr;
//   int i = 1941;
//   p = &i;
//   int j = *p;
//   printf("%d\n", j);

//   int x = 1, y = 2;
//   swapi(&x, &y);
//   printf("x=%d, y=%d\n", x, y);
// }

// int main() {
//   char nc = 'x';
//   const char c = nc;
//   const char* ncpc;
//   ncpc = &nc;
//   ncpc = &c;

//   char* const cpnc1 = &nc;
//   // char* const cpnc2 = &c; // error

//   const char* const cpc1 = &nc;
//   const char* const cpc2 = &c;
// }

// char* strcpy(char* dst, const char* src) {
//   char* const dst_orig = dst;
//   while (true) {
//     *dst = *src;
//     if (*dst == '\0') {
//       return dst_orig;
//     }
//     dst++;
//     src++;
//   }
// }

// int main() {
//   char greeting[13] = "hello";
//   char* tmp = greeting + strlen(greeting);
//   printf("%s - %ld\n", tmp, strlen(tmp));
//   // strncat(greeting, ", worldssdfsd", sizeof(greeting) - strlen(greeting) - 1);
//   int missing = snprintf(greeting + strlen(greeting), sizeof(greeting) - strlen(greeting), "%s", ", worldsdfasdf");
//   puts(greeting);
//   printf("%d\n", missing);
// }

// char* mstrcat(const char* s1, const char* s2) {
//   const size_t s1_len = strlen(s1);
//   char* const s12 = malloc(s1_len + strlen(s2) + 1);
//   // strcpy(s12, s1);
//   // strcpy(s12 + s1_len, s2);
//   sprintf(s12, "%s%s", s1, s2);
//   printf("%ld\n", strlen(s12));
//   return s12;
// }

// int main() {
//   char* const msg = mstrcat("hello", ", world");
//   puts(msg);
//   free(msg);
// }

struct string {
  char* contents;  // pointer to actual contents
  size_t length;   // length (not including null at end
};

void string_puts(struct string* str, const char* s) {
  const size_t new_len = str->length + strlen(s);
  str->contents = realloc(str->contents, new_len + 1);
  strcpy(str->contents + str->length, s);
  str->length = new_len;
}

void string_cleanup(struct string* str) {
  free(str->contents);
  *str = (struct string){};
}

int main() {
  struct string str = {.contents = "hello", .length = 5};
  puts(str.contents);

  struct string* pstr = &str;
  puts((*pstr).contents);
  puts(pstr->contents);  // same as: (*pstr).contents

  struct string str1 = {};
  string_puts(&str1, "hello");
  string_puts(&str1, ", world");
  puts(str1.contents);
  printf("%ld\n", str1.length);
  string_cleanup(&str1);
}
