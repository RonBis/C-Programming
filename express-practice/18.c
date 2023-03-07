#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if(argc < 3) {
    printf("Too few arguments.\n");
    exit(0);
  }

  FILE *src = fopen(argv[1], "r");
  if(src == NULL) {
    printf("Cannot locate file.\n");
    exit(1);
  }

  FILE *dest = fopen(argv[2], "w");
  if(dest == NULL) {
    printf("Cannot create file.\n");
    exit(1);
  }

  char ch;
  while((ch = getc(src)) != EOF) {
    if(ch != ' '){
      fputc(ch, dest);
    }
  }

  fclose(src);
  fclose(dest);
  return 0;
}
