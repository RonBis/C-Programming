#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int r, c, i, j;
  printf("Enter number of row: ");
  scanf("%d", &r);
  printf("Enter number of column: ");
  scanf("%d", &c);

  int **arr = (int **)malloc(sizeof(int *) * r);
  printf("Enter array elements: ");

  for (i = 0; i < r; i++) {
    int *row = (int *)malloc(sizeof(int) * c);
    for (j = 0; j < c; j++) {
      scanf("%d", row + j);
    }

    *(arr + i) = row;
  }

  printf("Print array elements: ");
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      // each row is *(arr + i)
      int elem = *(*(arr + i) + j);
      printf("%d ", elem);
    }
  }
  printf("\n");
  return 0;
}
