#include <stdio.h>

int main() {
  int n1, n2;

  printf("Enter two numbers (seperated by space): ");
  scanf("%d %d", &n1, &n2);

  int tmp = n1;
  if (n1 > n2) {
    n1 = n2;
    n2 = tmp;
  }

  while (n1 != 0) {
    tmp = n1;
    n1 = n2 % n1;
    n2 = tmp;
  }
  printf("GCD is %d\n", tmp);

  return 0;
}
