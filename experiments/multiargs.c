#include <stdarg.h>
#include <stdio.h>

int sum(int n, ...) {
  va_list n_list;
  va_start(n_list, n);

  for (int i = 0; i < n; i++)
  {
    printf("%d\n", va_arg(n_list, int));
  }
  va_end(n_list);
}

int main() {
  sum(3, 1, 2, 3);
  return 0;
}
