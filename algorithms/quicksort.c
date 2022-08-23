#include <stdio.h>

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

int main() {
  int arr[10] = {33, 37, 9, 47, 35, 24, 12, 0, 19, 20};
  quicksort(arr, 0, 9);

  for (int i = 0; i < 10; i++) {
    printf("%d  ", arr[i]);
  }

  printf("\n");
  return 0;
}
