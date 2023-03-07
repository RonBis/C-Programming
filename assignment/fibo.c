#include <stdio.h>

int main() {
  int n, count = 2;

  while (1) {
    printf("How many terms to print? ");
    scanf("%d", &n);

    if (n < 1) {
      printf("Number of terms cannot be less than 1.\n\n");
      continue;
    }

    long t1 = 0, t2 = 1;
    long next = t1 + t2;
    printf("Fibonacci numbers:\n0\n1\n");

    while (count < n) {
      printf("%ld\n", next);
      t1 = t2;
      t2 = next;
      next = t1 + t2;
      count++;
    }
    break;
  }

  return 0;
}
