#include <stdio.h>

int len(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++)
    ;
  return i;
}

void strrev(char *str) {
  int length = len(str);
  if (length == 0)
    return;

  strrev(str + 1);
  printf("%c", str[0]);
}

int main() {
  strrev("ronil");
  printf("\n");
  return 0;
}
