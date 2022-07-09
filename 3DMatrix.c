#include <stdio.h>
#include <stdlib.h>

int main() {
  int xsize, ysize, zsize;
  int ***mat;

  printf("Enter matrix dimensions [x y z] : ");
  scanf("%d %d %d", &xsize, &ysize, &zsize);

  // allocate memory for 3d array
  mat = (int ***)malloc(xsize * sizeof(int **));
  if (mat == NULL) {
    fprintf(stderr, "Not enough memory\n");
    exit(1);
  }
  for (int x = 0; x < xsize; x++) {
    mat[x] = (int **)malloc(xsize * sizeof(int *));
    if (mat[x] == NULL) {
      fprintf(stderr, "Not enough memory\n");
      exit(1);
    }

    for (int y = 0; y < ysize; y++) {
      mat[x][y] = (int *)malloc(ysize * sizeof(int));
      if (mat[x][y] == NULL) {
        fprintf(stderr, "Not enough memory\n");
        exit(1);
      }
    }
  }

  for (int x = 0; x < xsize; x++) {
    for (int y = 0; y < ysize; y++) {
      for (int z = 0; z < zsize; z++) {
        mat[x][y][z] = rand() % 100;
        printf("element [%d, %d, %d] = %d\n", x + 1, y + 1, z + 1,
               mat[x][y][z]);
      }
    }
  }

  return 0;
}
