#include <stdio.h>

int main(void) {
  int n;

  while (1) {
    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n < 1) {
      printf("Number of terms cannot be less than 1.\n\n");
      continue;
    }
    break;
  }

  double sum = 0.0;
  for (int i = 1; i <= n; i++) {
    sum = sum + 1/(double)i;
  }

  printf("Sum is: %lf\n", sum);
  return 0;
}
