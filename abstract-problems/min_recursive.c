#include <stdio.h>

int find_min(int *arr, int size, int min) {
  if (min > arr[size-1]) {
    min = arr[size-1];
    return find_min(arr, size-1, min);
  } else if(size > 0) {
    find_min(arr, size-1, min);
  } else {
    return min;
  }
}

int main() {
  int arr[10] = {5, 7, 8, 2, 13, 11, 4, 2, -11, 10};
  
  printf("%d\n", find_min(arr, 10, arr[0]));
  return 0;
}
