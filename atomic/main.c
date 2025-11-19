#include <threads.h>

#if __cplusplus >= 202302L  // C++23 or later?
#define _Atomic(T) std::atomic<T>
#endif

bool _Atomic shutdown;  // Thread-safe

static int worker_thread(void*) {
  while (!shutdown) {
    // ...
  }
  return 0;
}

double sqrt(double);
float sqrtf(float);
long double sqrtl(long double);

#define sqrt(N) \
  _Generic((N), float: sqrtf, long double: sqrtl, default: sqrt)((N))

void update_ptr(int* p, int* q, const int* restrict v) {
  *p += *v;
  *q += *v;
}

int main() {
  thrd_t t;
  thrd_create(&t, &worker_thread, nullptr);

  while (!shutdown) {
    // ...
    if (true) {
      shutdown = true;
    }
  }
  thrd_join(t, nullptr);
}
