#include <stdio.h>

int bucketsort(int *arr, int size) {
  for (int bucket = size / 2; bucket >= 1; bucket /= 2) {
    for (int j = bucket; j < size; j++) {
      for (int i = j - bucket; i >= 0; i++) {
        if (arr[i] > arr[j]) {
          int tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        } else {
          break;
        }
      }
    }
  }
}

int main() {
  int arr[10] = {33, 37, 9, 47, 35, 24, 12, 0, 19, 20};

  bucketsort(arr, 10);
  for (int i = 0; i < 10; i++) {
    printf("%d  ", arr[i]);
  }

  printf("\n");
  return 0;
}
