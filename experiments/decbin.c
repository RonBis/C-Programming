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
  int num, bin = 0;

  printf("Enter decimal: ");
  scanf("%d", &num);

  if (num != 0) {
    while (1) {
      int pos = 0;
      while ((num - pow_n(2, pos)) >= 0) {
        pos++;
      }
      pos--;

      bin += pow_n(10, pos);
      num %= pow_n(2, pos);

      if (num == 0)
        break;
    }
  }

  printf("Binary is: %d\n", bin);
}
