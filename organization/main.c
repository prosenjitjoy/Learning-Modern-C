#include <stdio.h>
#include <threads.h>

#ifdef __cplusplus
#define EXTERN_C extern "C"  // compiling with c++
#else
#define EXTERN_C /*nothing*/  // compiling with c
#endif

static int print_msg(void* thread_data) {
  const char* const msg = thread_data;
  fputs(msg, stdout);
  return 0;
}

bool shutdown;
mtx_t shutdown_mtx;

static bool load_bool_mtx(bool* src, mtx_t* mtx) {
  mtx_lock(mtx);
  const bool value = *src;
  mtx_unlock(mtx);
  return value;
}

static void store_bool_mtx(bool* dst, bool value, mtx_t* mtx) {
  mtx_lock(mtx);
  *dst = value;
  mtx_unlock(mtx);
}

static int worker_thread(void*) {
  while (!load_bool_mtx(&shutdown, &shutdown_mtx)) {
    // ...
  }
  return 0;
}

int main() {
  // thrd_t t;
  // thrd_create(&t, &print_msg, (void*)"Hello, World!\n");
  // thrd_join(t, nullptr);

  mtx_init(&shutdown_mtx, mtx_plain);
  thrd_t t;
  thrd_create(&t, &worker_thread, nullptr);

  while (!load_bool_mtx(&shutdown, &shutdown_mtx)) {
    // ...
    if (true) {
      store_bool_mtx(&shutdown, true, &shutdown_mtx);
    }
  }

  thrd_join(t, nullptr);
  mtx_destroy(&shutdown_mtx);
}
