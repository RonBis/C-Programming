#include <stdio.h>

void f2(int);
void f1(int n) {
  if (n < 11) {
    printf("%d ", n);
    f2(n + 1);
  }
}
void f2(int n) {
  if (n < 11) {
    printf("%d ", n);
    f1(n + 1);
  }
}

void even(int);
void odd(int i) {
  if (i < 11) {
    printf("%d ", i + 1);
    even(i + 1);
  }
}
void even(int i) {
  if (i < 11) {
    printf("%d ", i - 1);
    odd(i + 1);
  }
}

int main() {
  f1(1);
  printf("\n");
  odd(1);
  printf("\n");

  return 0;
}