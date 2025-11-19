#include <stdio.h>

#if __APPLE__
[[maybe_unused]] constexpr chat PLATFORM[] = "Apple";
#elif __linux__
[[maybe_unused]] constexpr char PLATFORM[] = "Linux";
#elif __WIN32
[[maybe_unused]] constexpr char PLATFORM[] = "Windows";
#else
[[maybe_unused]] constexpr char PLATFORM[] = "Generic";
#endif

#if __GNUC__
[[maybe_unused]] constexpr char COMPILER[] = "GCC";
#elif __clang__
[[maybe_unused]] constexpr char COMPILER[] = "LLVM";
#elif _MSC_VER
[[maybe_unused]] constexpr char COMPILER[] = "MSVC";
#else
[[maybe_unused]] constexpr char COMPILER[] = "Unknown";
#endif

#if __aarch64__
[[maybe_unused]] constexpr char ARCHITECTURE[] = "arm64";
#elif __x86_64__
[[maybe_unused]] constexpr char ARCHITECTURE[] = "amd64";
#else
[[maybe_unused]] constexpr char ARCHITECTURE[] = "unknown";
#endif

#ifndef MSG
#define MSG "undefined"
#endif  // MSG

#define ENABLE_TERM_SIZE false
#if ENABLE_TERM_SIZE
[[maybe_unused]] constexpr size_t TERM_SIZE = 4096;
#endif

#if 0
// ... commented code...
#endif

#if __has_c_attribute(gnu::hot)
#define ATTRIBUTE_HOT [[gnu::hot]]
#else
#define ATTRIBUTE_HOT  // nothing
#endif

#if __has_include(<readline/readline.h>)
#define WITH_READLINE true
#endif

#define ARRAY_SIZE(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

#define STRINGIFY(X) #X
#define PASTE(A, B, C) A##B##C

#undef VERSION

constexpr unsigned char ALARM_SOUND[] = {
#embed "alarm.wav"
};

int main() {
  printf("Platform: %s\n", PLATFORM);
  printf("Compiler: %s\n", COMPILER);
  printf("Architecture: %s\n", ARCHITECTURE);

  printf("%s\n", MSG);
  printf("%ld\n", __STDC_VERSION__);
  printf("%s\n", __DATE__);
  printf("%s\n", __TIME__);

#define N false
#if N
  // ...
  printf("This line execute if N has non-zero value\n");
#endif
#if defined N
  printf("N is defined with any value\n");
#endif

  int arr[] = {1, 2, 3, 5};
  printf("%lu\n", ARRAY_SIZE(arr));
  printf("%d\n", MAX(arr[0] + arr[1] + arr[2], arr[3]));

  printf("%s\n", STRINGIFY(true false));
  printf("%d\n", PASTE(1, 2, 3));

// #error "a error message"
#warning "a warning message"

  for (size_t i = 0; i < 10; i++) {
    printf("%d, ", ALARM_SOUND[i]);
  }
}
