#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readfile(FILE *fp) {
  // find out the file content length
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);

  rewind(fp); // move pointer back to start

  char *str = malloc(fsize + 1);
  fread(str, fsize, sizeof(char), fp);
  str[fsize] = '\0'; // terminate the string

  return str;
}

int main(void) {
  FILE *fp1, *fp2, *fp_out;
  char *file1, *file2;

  fp1 = fopen("1.txt", "r");
  file1 = readfile(fp1);

  fp2 = fopen("2.txt", "r");
  file2 = readfile(fp2);

  remove("_merged.txt");
  fp_out = fopen("_merged.txt", "a");
  fprintf(fp_out, "%s", file1);
  fprintf(fp_out, "%s", file2);

  fclose(fp_out);
  fclose(fp2);
  fclose(fp1);

  return 0;
}
