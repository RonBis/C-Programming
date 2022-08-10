#include <stdio.h>
#include <stdlib.h>

int main() {
  int matrix_size;
  int **mat;
  FILE *fp;

  printf("Enter matrix size : ");
  scanf("%d", &matrix_size);

  // allocate memory for 2d array of size [matrix_size]x[matrix_size]
  mat = (int **)malloc(matrix_size * sizeof(int *));
  if (mat == NULL) {
    fprintf(stderr, "Not enough memory\n");
    exit(1);
  }
  for (int row = 0; row < matrix_size; row++) {
    mat[row] = (int *)malloc(matrix_size * sizeof(int));
    if (mat[row] == NULL) {
      fprintf(stderr, "Not enough memory\n");
      exit(1);
    }
  }

  int num_iter = (matrix_size + 1) / 2;
  int count = 0, val = num_iter;
  while (count < num_iter) {
    int start = count, end = matrix_size - count - 1;
    for (int i = start; i <= end; i++) {
      if (i == start) {
        mat[i][i] = val;
      } else {
        mat[i][start] = mat[start][i] = val;
      }
    }

    for (int i = start + 1; i <= end; i++) {
      if (i == end) {
        mat[i][i] = val;
      } else {
        mat[i][end] = mat[end][i] = val;
      }
    }

    val--, count++;
  }

  printf("\nGenerated matrix : \n\n");
  for (int r = 0; r < matrix_size; r++) {
    for (int c = 0; c < matrix_size; c++) {
      printf("%d  ", mat[r][c]);
    }
    printf("\n");
  }

  fp = fopen("matrix_output.txt", "w");
  for (int r = 0; r < matrix_size; r++) {
    for (int c = 0; c < matrix_size; c++) {
      fprintf(fp, "%d  ", mat[r][c]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);
  free(mat);
  return 0;
}
