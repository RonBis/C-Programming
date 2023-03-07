#include <stdio.h>

int main() {
  int lower_lim, upper_lim;

  while (1) {
    printf("Enter lower range: ");
    scanf("%d", &lower_lim);

    printf("Enter upper range: ");
    scanf("%d", &upper_lim);

    if (lower_lim < 0 || upper_lim < 0) {
      printf("Range cannot be negative.\n\n");
      continue;
    } else if (lower_lim >= upper_lim) {
      printf("Invalid lower range given.\n\n");
      continue;
    }
    break;
  }

  printf("The armstrong numbers between %d and %d are:\n", lower_lim,
         upper_lim);
  for (int i = lower_lim; i <= upper_lim; i++) {
    int arm = 0, ncopy = i;
    while (i != 0) {
      int r = i % 10;
      arm += r * r * r;
      i /= 10;
    }

    i = ncopy;
    if (ncopy == arm) {
      printf("%d\n", arm);
    }
  }
  return 0;
}