#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int m;
  printf("Enter size: ");
  scanf("%d", &m);

  int **arr = (int **)malloc(sizeof(int *) * m);
  for (int i = 0; i < m; i++) {
    int *row = (int *)malloc(sizeof(int) * m);
    *(arr + i) = row;
  }

  int levels = ceilf((float)m / 2) - 1;

  for (int lvl = 0; lvl <= levels; lvl++) {
    int ringVal = levels - lvl + 1;
    int i, j;

    for(i = lvl, j = lvl+1; j<=ringVal+1; j++) {
      arr[i][j] = ringVal;
    }
    for(i = ringVal+1, j=lvl; j<=ringVal; j++) {
      arr[i][j] = ringVal;
    }
    for(i = lvl+1, j=ringVal+1; i<=ringVal+1; i++) {
      arr[i][j] = ringVal;
    }
    for(i=lvl, j=lvl; i<=ringVal; i++) {
      arr[i][j] = ringVal;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d  ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}