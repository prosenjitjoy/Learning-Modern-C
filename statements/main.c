#include <stdio.h>
#include <stdlib.h>

struct slist {
  struct slist* next;
  void* data;
};

[[nodiscard]]
struct slist* slist_push(struct slist* head, void* data) {
  struct slist* const new_head = malloc(sizeof(struct slist));
  new_head->next = head;
  new_head->data = data;
  return new_head;
}

[[nodiscard]]
void* slist_peek(struct slist* head) {
  return head != nullptr ? head->data : nullptr;
}

[[nodiscard]]
void* slist_pop(struct slist** phead) {
  const auto head = *phead;
  if (head == nullptr) {
    return nullptr;
  }

  *phead = head->next;
  const auto data = head->data;
  free(head);
  return data;
}

enum color {
  COLOR_BLACK = -1,
  COLOR_WHITE,
  COLOR_BLUE,
  COLOR_GREEN,
  COLOR_RED,
};

enum ansi_color {
  ANSI_RESET,
  ANSI_BOLD,
  ANSI_FG_BLACK = 30,
  ANSI_FG_RED = 31,
  ANSI_FG_GREEN = 32,
  ANSI_FG_YELLOW = 33,
  ANSI_FG_BLUE = 34,
  ANSI_FG_MAGENTA = 35,
  ANSI_FG_CYAN = 36,
  ANSI_FG_WHITE = 37,
  ANSI_BG_BLACK = 40,
  ANSI_BG_RED = 41,
  ANSI_BG_GREEN = 42,
  ANSI_BG_YELLOW = 43,
  ANSI_BG_BLUE = 44,
  ANSI_BG_MAGENTA = 45,
  ANSI_BG_CYAN = 46,
  ANSI_BG_WHITE = 47,
};

int main() {
  int a[9] = {
      [3] = 1,
      [4] = 2,
      [5] = 3,
  };

  for (size_t i = 0; i < 9; i++) {
    printf("%zu: %d\n", i, a[i]);
  }

  const char* const COLORS[] = {"blacksafsf", "white", "blue", "green", "red"};
  printf("%s\n", COLORS[4]);
  const char COLORS_2D[][6] = {"black", "white", "blue", "green", "red"};
  printf("%s\n", COLORS_2D[0]);

  [[maybe_unused]]
  enum color c = COLOR_RED;

  printf("\33[%dm", ANSI_FG_BLACK);
  printf("\33[%dm", ANSI_BOLD);
  printf("\33[%dm", ANSI_BG_WHITE);
  printf("%d\n", c);
}
