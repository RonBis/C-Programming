#include <stdio.h>

typedef struct SparseMatVal {
  int row, col, val;
} spval;

int main() {
  int row, col;
  printf("Enter row and col: ");
  scanf("%d %d", &row, &col);

  int mat[row][col];

  int count, i = 1;
  printf("Number of non-zero values: ");
  scanf("%d", &count);

  spval A[count + 1], B[count + 1];
  A[0].row = row, A[0].col = col, A[0].val = count;
  B[0].row = row, B[0].col = col, B[0].val = count;

  // fill the matrix with zeros
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      mat[i][j] = 0;
    }
  }

  // insert the non-zero values
  printf("\n");
  while (i <= count) {
    printf("A[%d] row, col, val: ", i);
    scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].val);

    mat[A[i].row][A[i].col] = A[i].val;
    i++;
  }

  // print the matrix before transposing
  printf("\nInitial matrix:\n");
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%2d  ", mat[i][j]);
    }
    printf("\n");
  }

  // do transpose
  printf("\n");
  for (int i = 1; i <= A[0].col; i++) {
    for (int j = 1; j <= A[0].val; j++) {
      B[i] = (spval){.row = A[i].col, .col = A[j].col, .val = A[i].val};
    }
    printf("B[%d] %3d %3d %3d\n", i, B[i].row, B[i].col, B[i].val);
  }

  return 0;
}
