#include <stdio.h>
#include <malloc.h>

void merge(float arr[], int p, int mid_pos, int r)
{
  int arr1_size = mid_pos - p + 1, arr2_size = r - mid_pos, arr_ksize = r - p + 1;
  float *arr1 = malloc(arr1_size * sizeof(float));
  float *arr2 = malloc(arr2_size * sizeof(float));
  float *arr_k = malloc(arr_ksize * sizeof(float));

  for (int i = 0; i < arr1_size; i++)
  {
    arr1[i] = arr[i];
  }
  for (int i = 0; i < arr2_size; i++)
  {
    arr2[i] = arr[mid_pos + 1 + i];
  }

  int i, j = 0;
  for (int k = 0; k < arr_ksize; k++)
  {
    if (i < arr1_size && j < arr2_size)
    {
      if (arr1[i] < arr2[j])
      {
        arr_k[k] = arr1[i++];
      }
      else if (arr1[i] >= arr2[j])
      {
        arr_k[k] = arr2[j++];
      }
    }
    else if (i == arr1_size && j != arr2_size)
    {
      for (int m = j; m < arr2_size; m++)
      {
        arr_k[k] = arr2[m];
      }
    }
    else if (i != arr1_size && j == arr2_size)
    {
      for (int m = i; m < arr1_size; m++)
      {
        arr_k[k] = arr1[m];
      }
    }
  }

  for (int i = 0; i < arr_ksize; i++)
  {
    printf("%.3f\n", arr_k[i]);
  }
}

void mergesort(float arr[], int p, int r)
{
  if (p < r)
  {
    int mid_pos = (p + r);
    mergesort(arr, p, mid_pos - 1);
    mergesort(arr, mid_pos, r);
    merge(arr, p, mid_pos, r);
  }
}

int main()
{
  // float arr[7] = {2.355, 4.5, 3.6, 2.12, 3.6, 6.4, 2.355};
  float arr[9] = {0, 10, 21, 47, 49, 8, 15, 20, 78};

  //mergesort(arr, 0, 6);
  merge(arr, 0, 4, 8);
  return 0;
}
