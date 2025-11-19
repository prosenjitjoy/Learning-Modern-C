#ifndef HEADER_H
#define HEADER_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

struct string {
  char* contents;
  size_t len;
};

void string_puts(struct string* str, const char* s);
void string_cleanup(struct string* str);

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // HEADER_H
