#include <stdio.h>

int main() {
  int row1, col1, row2, col2;

  printf("Matrix 1 - Enter row and col count(seperated by space): ");
  scanf("%d %d", &row1, &col1);

  int mat1[row1][col1];
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col1; j++) {
      printf("element[%d][%d]: ", i+1, j+1);
      scanf("%d", &mat1[i][j]);
    }
  }

  printf("\nMatrix 2 - Enter row and col count(seperated by space): ");
  scanf("%d %d", &row2, &col2);

  int mat2[row2][col2];
  for (int i = 0; i < row2; i++) {
    for (int j = 0; j < col2; j++) {
      printf("element[%d][%d]: ", i+1, j+1);
      scanf("%d", &mat2[i][j]);
    }
  }

  printf("\nGiven matrices are:\n");
  printf("\nMatrix 1:\n");
  for(int i=0; i<row1;i++) {
    for(int j=0; j<col1; j++) {
      printf("%d  ", mat1[i][j]);
    }
    printf("\n");
  }
  printf("\nMatrix 2:\n");
  for (int i = 0; i < row2; i++) {
    for (int j = 0; j < col2; j++) {
      printf("%d  ", mat2[i][j]);
    }
    printf("\n");
  }

  if ((row1 == row2) && (col1 == col2)) {
    printf("\nSum:\n");
    // 2d array for storing the sum
    int sum[row1][col1];

    // do sum
    for (int i = 0; i < row1; i++) {
      for (int j = 0; j < col1; j++) {
        sum[i][j] = mat1[i][j] + mat2[i][j];
        printf("%d  ", sum[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("\nSum isn't possible for given matrices.");
  }

  if (col1 == row2) {
    printf("\nProduct:\n");
    // dimension of product matrix is [row1][col2]
    // 2d array for storing the product
    int prod[row1][col2];

    // do mult
    for (int i = 0; i < row1; i++) {
      for (int j = 0; j < col2; j++) {
        prod[i][j] = 0;

        for (int k = 0; k < col1; k++) {
          prod[i][j] += mat1[i][k] * mat2[k][j];
        }
        printf("%d  ", prod[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("\nProduct isn't possible for given matrices.");
  }

  return 0;
}
