#include <stdio.h>

extern inline int gcd(int who, int bywho) {
  return bywho == 0 ? who : gcd(bywho, who % bywho);
}

int main(void) { printf("%d\n", gcd(26, 12)); }
