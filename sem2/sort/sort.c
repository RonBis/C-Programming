#include <stdio.h>
#include <stdlib.h>

#include "../testarr.h"

void swap(int *prev, int *next) {
  int temp = *prev;
  *prev = *next;
  *next = temp;
}

void display(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
  display(arr, n);
}

void selectionSort(int arr[], int n) {
  int step, j;
  for (step = 0; step < n - 1; step++) {
    int min_index = step;

    for (j = step + 1; j < n; j++) {
      if (arr[min_index] > arr[j]) {
        min_index = j;
      }
    }
    if (step != min_index) {
      swap(&arr[step], &arr[min_index]);
    }
  }
  display(arr, n);
}

int main() {
  int size = (int)(sizeof(arr) / sizeof(arr[0]));

  int choice;
  while (1) {
    printf("\n1. Bubble.\n2. Selection.\n3. Insertion.\n4. Merge.\n5. "
           "Quick.\n6. Heap.\n7. Shell.\n");
    printf("8. Exit.\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      bubbleSort(arr, size);
      break;

    case 2:
      selectionSort(arr, size);
      break;

      /*case 3: insertionSort();
              break;*/

    case 8:
      exit(0);

    default:
      printf("Wrong choice.\n");
    }
  }
}