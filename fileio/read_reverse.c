#include <stdio.h>

int main(void) {
  FILE *fp_r, *fp_w;
  fp_r = fopen("sample.txt", "r");
  fp_w = fopen("sample_output.txt", "w");

  fseek(fp_r, -1, SEEK_END);

  while (ftell(fp_r) >= 0) {
    putc(getc(fp_r), fp_w);

    /*  Since, fgetc or getc reads a character in current position
        and advances the file pointer, we have to seek 2 times backwards
        in order to compensate the pointer going forward  */
    if (ftell(fp_r) == 1) {
      break;
    } else {
      fseek(fp_r, -2, SEEK_CUR);
    }
  }

  fclose(fp_w);
  fclose(fp_r);

  return 0;
}
