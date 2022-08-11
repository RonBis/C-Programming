#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_string(FILE *src_stream, char *prompt) {
  int str_len = 0;
  char *str, ch;
  char stream_terminator = src_stream == stdin ? '\n' : EOF;

  str = malloc(sizeof(char));

  if (prompt != NULL) {
    printf("%s", prompt);
  }

  while ((ch = getc(src_stream)) != stream_terminator) {
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
  char *str_to_be_deleted, *fp_content;

  str_to_be_deleted = read_string(stdin, "String to be deleted > ");

  fp = fopen("sample.txt", "r+");
  fp_content = read_string(fp, NULL);

  printf("%d %d\n", (int)strstr(fp_content, str_to_be_deleted), (int)fp_content);

  fclose(fp);
  return 0;
}
