#include <stdio.h>
#include <stdlib.h>

char *read_string() {
  int str_len = 0;
  char *str, ch;

  str = malloc(sizeof(char));

  while ((ch = getchar()) != '\n') {
    // reallocate with size = str_len
    str = realloc(str, (str_len + 1) * sizeof(char));
    *(str + str_len) = ch;

    str_len++;
  }

  str = realloc(str, str_len + 1);
  *(str + str_len + 1) = '\0';

  return str;
}

int main(void) {
  char *str;

  str = read_string();
  printf("%s\n", str);

  return 0;
}
