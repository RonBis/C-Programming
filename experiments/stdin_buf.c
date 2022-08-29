#include <stdio.h>

int main() {
  char ch;
  while((ch = getc(stdin)) != 27) {
    printf("%c", ch);
  }

  return 0;
}
