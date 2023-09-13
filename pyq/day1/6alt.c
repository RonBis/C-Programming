#include <stdio.h>

int main() {
  int n;
  printf("Enter array size: ");
  scanf("%d", &n);

  int arr[10] = {41, 6, 24, 91, 69, 35, 59, 34, 29, -1};

  // for(int i=0; i<n; i++) {
  //   printf("arr[%d]: ", i);
  //   scanf("%d", &arr[i]);
  // }

  for(int i=0; i<n-1; i++) {
    int minIdx = i;
    for(int j=i+1; j<n; j++) {
      if(arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    if(minIdx != i) {
      // swap
      int t = arr[i];
      arr[i] = arr[minIdx];
      arr[minIdx] = t;
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d  ", arr[i]);
  }
  
  printf("\n");
  return 0;
}
