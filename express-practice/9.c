#include <stdio.h>

int main() {
  int n;
  while(1) {
    printf("Number of lines: ");
    scanf("%d", &n);

    if(n<1) {
      printf("Number of lines cannot be less than 1\n\n");
      continue;
    }
    break;
  }

  for(int i=1; i<=n; i++) {
    for(int spaces = 1; spaces <= n-i; spaces++) printf(" ");
    for(int stars = 0; stars < i*2-1; stars++) printf("*");
    printf("\n");
  }

  return 0;
}
