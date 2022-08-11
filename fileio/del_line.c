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

  str = realloc(str, (str_len + 1) * sizeof(char));
  *(str + str_len + 1) = '\0';

  return str;
}

int main(void) {
  FILE *fp;
  char *str_to_be_deleted, ch;

  // str_to_be_deleted = read_string();
  fp = fopen("sample.txt", "w+");

  while((ch == getc(fp)) != EOF) {
    printf("%c", ch);
  }

  return 0;
}
