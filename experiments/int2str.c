#include <stdio.h>

int main() {
  int n;
  printf("Enter number: ");
  scanf("%d", &n);

  char str[10];

  int ncopy = n, len = 0;
  while (ncopy > 0) {
    int r = ncopy % 10;
    str[len] = r + 48;
    len++;
    ncopy /= 10;
  }

  for (int i = 0; i < len / 2; i++) {
    char tmp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = tmp;
  }
  str[len] = '\0';

  printf("%s, %d\n", str, len);
  return 0;
}
