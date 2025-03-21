#include <stdio.h>
#include <stdlib.h>

void merge(float arr[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  float L[n1], R[n2];

  // Copy data to temporary arrays
  for (i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  // Merge the temporary arrays back into arr
  i = 0;
  j = 0;
  k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L and R if any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Function to perform Merge Sort
void mergeSort(float arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

// Function to print the array
void printArray(float arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%.2f ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  float arr[n];
  printf("Enter the elements:\n"); // elements in the array are taken as input
  for (int i = 0; i < n; i++) {
    scanf("%f", &arr[i]);
  }
  mergeSort(arr, 0, n - 1);

  printf("Sorted array using Merge Sort: ");
  printArray(arr, n);
  return 0;
}
