#include <stdio.h>

int min(int x, int y) { return x < y ? x : y; }

void merge(int arr[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int A[n1], B[n2];

  // copy array into new arrays
  for (int i = 0; i < n1; i++)
    A[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    B[j] = arr[q + 1 + j];

  int i = 0, j = 0, k = p;
  while (i < n1 && j < n2)
  {
    if (A[i] < B[j])
    {
      arr[k] = A[i++];
    }
    else
    {
      arr[k] = B[j++];
    }
    k++;
  }

  // copy rest
  while (i < n1)
    arr[k++] = A[i++];
  while (j < n2)
    arr[k++] = B[j++];
}

void mergesort(int A[], int p, int r)
{
  if (p < r)
  {
    int q = p + (r - p) / 2;
    mergesort(A, p, q);
    mergesort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

void mergesortIter(int A[], int n) {
  for(int curr_size = 1; curr_size <= n-1; curr_size *= 2) {
    for(int left_start = 0; left_start<n-1; left_start += 2*curr_size) {
      int mid = min(left_start + curr_size - 1, n-1);
      int right_end = min(left_start + 2*curr_size - 1, n-1);
      merge(A, left_start, mid, right_end);
    }
  }
}

int main()
{
  int arr[] = {42, 10, 70, 8, 7, 49, 66, 23, 47, 1};
  mergesortIter(arr, 10);
  for (int i = 0; i < 10; i++)
  {
    printf("%d  ", arr[i]);
  }
  printf("\n");
  return 0;
}
