#include <stdio.h>

int pow_n(int base, int power) {
  if (power == 0) {
    return 1;
  }

  int val = 1;
  for (int i = 1; i <= power; i++) {
    val *= base;
  }
  return val;
}

int main() {
  int num, bin = 0, rem, n = 0;
  printf("Decimal: ");
  scanf("%d", &num);

  while (num >= pow_n(2, n)) {
    n++;
  }

  for (int m = 1; m <= n; m++) {
    rem = num % 2;
    bin += rem * pow_n(10, m);
    num /= 2;
  }

  printf("Binary is: %d\n", bin/10);
  return 0;
}
