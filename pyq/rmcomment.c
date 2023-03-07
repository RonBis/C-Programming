#include <stdio.h>

#define NO_COMMENT 0
#define COMMENT_HALF_START 1
#define COMMENT_FULL_START 2
#define COMMENT_HALF_END 3
// #define COMMENT_FULL_END 4

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("Provide a source file.\n");
    return 0;
  }

  FILE *src = fopen(argv[1], "r");
  if (src == NULL) {
    printf("Cannot read source file.\n");
    return 0;
  }

  char content[5000];
  int content_len = 0;

  int state = NO_COMMENT;
  char ch;
  while ((ch = fgetc(src)) != EOF) {
    if (state == NO_COMMENT) {
      if (ch == '/') {
        state = COMMENT_HALF_START;
      } else {
        content[content_len++] = ch;
      }
    } else if (state == COMMENT_HALF_START) {
      if (ch == '*') {
        state = COMMENT_FULL_START;
      } else {
        state = NO_COMMENT;
      }
    } else if (state == COMMENT_FULL_START && ch == '*') {
      state = COMMENT_HALF_END;
    } else if (state == COMMENT_HALF_END) {
      if (ch == '/') {
        state = NO_COMMENT;
      } else {
        state = COMMENT_FULL_START;
      }
    }
  }
  content[content_len] = '\0';
  fclose(src);

  FILE *out = fopen(argv[1], "w");
  fputs(content, out);
  fclose(out);

  return 0;
}