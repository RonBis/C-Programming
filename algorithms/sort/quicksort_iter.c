#include <stdio.h>

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return i + 1;
}

void quicksort(int *arr, int low, int high) {
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int pivot_index = partition(arr, low, high);

        if (pivot_index - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivot_index - 1;
        }

        if (pivot_index + 1 < high) {
            stack[++top] = pivot_index + 1;
            stack[++top] = high;
        }
    }
}

int main() {
    int arr[10] = {33, 37, 9, 47, 35, 24, 12, 0, 19, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }

    printf("\n");
    return 0;
}
