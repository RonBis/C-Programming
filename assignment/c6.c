#include <stdio.h>

int main(void) {
  int n;

  while (1) {
    printf("Enter the number: ");
    scanf("%d", &n);

    if (n < 1) {
      printf("Number cannot be less than 1.\n\n");
      continue;
    }
    break;
  }

  printf("The factors of %d are:\n", n);
  for (int i = 1; i <= n / 2; i++) {
    if (n % i == 0) {
      printf("%d\n", i);
    }
  }
  // as n itself is a factor of n
  printf("%d\n", n);
  return 0;
}