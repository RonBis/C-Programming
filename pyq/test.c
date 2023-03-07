// WAP in C that reads a file which contains integer line wise. Sum these
// integers and store the result at the end of the file.
#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *src = fopen("abc.txt", "r");
  if (src == NULL) {
    printf("Error in opening file.\n");
    exit(1);
  }
  int num, sum = 0;
  char arr[100];
  while (fgets(arr, 100, src)) {
    int num = atoi(arr);
    sum += num;
  }

  fclose(src);
  FILE *dest = fopen("abc.txt", "a");
  if (dest == NULL) {
    printf("Error in opening file.\n");
    exit(1);
  }

  fprintf(dest, "\nSUM = %d\n", sum);
  fclose(dest);
  printf("Sum has been displayed.\n");
  return 0;
}