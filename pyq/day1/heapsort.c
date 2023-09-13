#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void heapify(int arr[], int size, int i)
{
  // find largest among root, left and right
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && arr[left] > arr[largest])
    largest = left;
  if (right < size && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, size, largest);
  }
}

void heapsort(int arr[], int size) {
  // build max heap
  for(int i = size / 2 - 1; i >= 0; i--)
    heapify(arr, size, i);
  
  // sort
  for(int i = size - 1; i >= 0; i--) {
    // swap root and last element
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{
  int n;
  printf("Enter array size: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter array elements (separate by space)\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("\n");
  heapsort(arr, n);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}