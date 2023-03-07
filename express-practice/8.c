#include <stdio.h>

#define swap(a, b)                                                             \
  {                                                                            \
    a ^= b;                                                                    \
    b ^= a;                                                                    \
    a ^= b;                                                                     \
  }

int main() {
  int a = 5, b = 7;
  swap(a, b);
  printf("%d, %d\n", a, b);
  return 0;
}
