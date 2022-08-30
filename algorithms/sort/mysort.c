#include <stdio.h>

void sort(int *arr, int arr_start, int arr_end, int p1, int p2, int pivot) {
  while (p1 <= pivot) {
    if (arr[p1] < arr[pivot]) {
      p1++;
    } else {
      break; // halt
    }
  }
  while (p2 >= pivot) {
    if (arr[p2] > arr[pivot]) {
      p2--;
    } else {
      break; // halt
    }
  }

  // now both are halted
  // case 1: If p1 has reached pivot and p2 hasn't reached pivot
  // As p2 is halted, swap b2n pivot and p2
  if (p1 == pivot && p2 != pivot) {
    int tmp = arr[pivot];
    arr[pivot] = arr[p2];
    arr[p2] = tmp;

    p2--;
    p1 = arr_start; // resetting p1
  }

  // case 2: If p2 has reached pivot and p1 hasn't reached pivot
  // As p1 is halted, swap b2n pivot and p1
  else if (p2 == pivot && p1 != pivot) {
    int tmp = arr[pivot];
    arr[pivot] = arr[p1];
    arr[p1] = tmp;

    p1++;
    p2 = arr_end; // resetting p2
  }

  // case 3: If neither have reached pivot (Do a simple swap
  // b2n p1 & p2)
  else if (p1 != pivot && p2 != pivot) {
    int tmp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = tmp;
  }

  // case 4: If both have reached pivot
  else if (p1 == pivot && p2 == pivot && ((pivot - arr_start != 2) || (pivot - arr_start != 3))) {
    sort(arr, arr_start, pivot, arr_start, pivot, (arr_start + pivot) / 2);
    sort(arr, pivot + 1, arr_end, pivot + 1, arr_end, (pivot + arr_end) / 2);
  }

  for (int x = 0; x < 6; x++) {
    printf("%d\t", arr[x]);
  }
  printf("\n");

  sort(arr, arr_start, arr_end, p1, p2, pivot);
}

int main(void) {
  // int arr[10] = {33, 37, 9, 47, 35, 24, 12, 0, 19, 20};
  int arr[6] = {20, 13, 5, 99, 7, 35};

  printf("Begin sorting : \n");
  // sort(arr, 0, 9, 0, 9, 4);
  sort(arr, 0, 5, 0, 5, 2);

  return 0;
}
