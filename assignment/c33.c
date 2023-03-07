#include <stdio.h>

int main(int argc, char *argv[]) {
  if(argc < 3) {
    printf("Too few arguments.\n");
    return 0;
  }

  FILE *src = fopen(argv[1], "r");
  if(src == NULL) {
    printf("Source doesn't exist.\n");
    return 0;
  }

  FILE *dest = fopen(argv[2], "w");

  char ch;
  while((ch = fgetc(src)) != EOF) {
    if(ch == ' ') continue;
    fputc(ch, dest);
  }

  return 0;
}
