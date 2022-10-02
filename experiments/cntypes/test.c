#include <stdio.h>
#include "types.h"

_float sum(float n1, float n2) {
  return (_float){ .val = n1 + n2, .null = false };
}

int main() {
  printf("Sum: %f\n", sum(1, 2).val);

  int a = 5;
  _int _a = toNullable(int, 5);

  printf("nullable a = %d\n", _a.val);

  a=NULL, _a.val=NULL;
  printf("%p\n", a+_a.val);

  return 0;
}
