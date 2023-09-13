#include <stdio.h>

int main()
{
  int n, i, min, t;
  printf("Enter Array Size: ");
  scanf("%d", &n);
  // int A[n];
  // printf("Enter %d Values(seperated with ','): ", n);
  // for(i=0;i<n;i++){
  //     scanf("%d, ",&A[i]);
  // }

  int A[10] = {41, 6, 24, 91, 69, 35, 59, 34, 29, -1};

  printf("\nUnsorted\n ");
  for (i = 0; i < n; i++)
  {
    printf("%d, ", A[i]);
  }

  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++) {
      if (A[min] >= A[j])
        min = j;
    }
    if (min != i) {
      t = A[i];
      A[i] = A[min];
      A[min] = t;
    }
  }

  printf("\nSorted\n ");
  for (i = 0; i < n; i++)
  {
    printf("%d, ", A[i]);
  }

  return 0;
}
// {41, 6, 24, 91, 69, 35, 59, 34, 29, 82}