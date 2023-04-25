#include <stdio.h>
#include <time.h>

#include "../testarr.h"

void swap(int *arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

int partition(int *arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr, i, j);
    }
  }

  swap(arr, i + 1, high);
  return i + 1;
}

int quicksort(int *arr, int low, int high) {
  if (low < high) {
    int part_index = partition(arr, low, high);

    quicksort(arr, low, part_index - 1);
    quicksort(arr, part_index + 1, high);
  }
}

int binarySearchR(int arr[], int x, int low, int high) {
  if (low > high)
    return -1;

  int mid = low + (high - low) / 2;
  if (x == arr[mid]) {
    return mid;
  } else if (x > arr[mid]) {
    binarySearchR(arr, x, mid + 1, high);
  } else {
    binarySearchR(arr, x, low, mid - 1);
  }
}

int binarySearchI(int arr[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (x > arr[mid]) {
      low = mid + 1;
    } else if (x < arr[mid]) {
      high = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int main() {
  quicksort(arr, 0, 999);
  int length = (int)(sizeof(arr) / sizeof(arr[0]));

  int toBeSearched;
  printf("Enter item to be searched: ");
  scanf("%d", &toBeSearched);

  char meth;
  printf("Method [iterative(i)/recursive(r)]: ");
  scanf(" %c", &meth);

  int pos;
  clock_t start_time = clock();

  if (meth == 'r') {
    pos = binarySearchR(arr, toBeSearched, 0, length - 1);
  } else {
    pos = binarySearchI(arr, toBeSearched, 0, length - 1);
  }

  double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
  printf("found at pos: %d\n", pos);
  printf("Done in %lf seconds.\n", elapsed_time);

  return 0;
}
