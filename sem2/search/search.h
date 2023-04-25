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