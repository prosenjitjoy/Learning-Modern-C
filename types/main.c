#include <assert.h>
#include <complex.h>
#include <float.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <uchar.h>

#define complex _Complex

constexpr unsigned TAB_STOP = 8;

double complex euler(double x) { return cexp(I * x); }

typedef char int32_buf[4];  // type: array of 4 char
int32_buf buf;

typedef unsigned short process_id;
process_id pid;

typedef unsigned short user_id;
// user_id uid = pid;

int main() {
  int x = 1'000'000'000;
  printf("%d\n", x);

  unsigned _BitInt(3) y = 7uwb;
  printf("%u\n", (unsigned)y);

  int8_t signed_8bit_int;
  int16_t signed_16bit_int;
  int32_t signed_32bit_int;
  int64_t signed_64bit_int;
  intmax_t largest_signed_int;
  intptr_t pointer_sized_signed_int;

  assert(sizeof(signed_64bit_int) == sizeof(largest_signed_int));

  uint8_t unsigned_8bit_int;
  uint16_t unsigned_16bit_int;
  uint32_t unsigned_32bit_int;
  uint64_t unsigned_64bit_int;
  uintmax_t largest_unsigned_int;
  uintptr_t pointer_sized_unsigned_int;

  assert(sizeof(unsigned_64bit_int) == sizeof(largest_unsigned_int));

  constexpr char8_t SMILEY_FACE[] = u8"\xF0\x9F\x99\x82";
  printf("%s\n", SMILEY_FACE);

  char16_t utf16_encoded_char;
  char32_t utf32_encoded_char;

  max_align_t maximum_alignment_type;
  nullptr_t nullptr_type;
  ptrdiff_t pointer_difference_type;
  size_t unsigned_size_in_bytes;
  ssize_t signed_size_in_bytes;
  time_t signed_time_relative_to_epoch;

  printf("float: (%g, %g)\n", FLT_MIN, FLT_MAX);
  printf("double: (%lg, %lg)\n", DBL_MIN, DBL_MAX);
  printf("long double: (%Lg, %Lg)\n", LDBL_MIN, LDBL_MAX);

  int i = INT_MAX;
  printf("%d\n", ++i);
}
