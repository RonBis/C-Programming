#include <stdio.h>

int main() {
  int n;
  while(1) {
    printf("Number of turns: ");
    scanf("%d", &n);

    if(n < 1) {
      printf("No of terms cannot be less than 1.\n\n");
      continue;
    }
    break;
  }

  int sum = 0;
  for(int i=1; i<=n; i++) {
    sum = sum + ((i%2 != 0) ? i:-i);
  }
  printf("Sum: %d\n", sum);

  return 0;
}
