#include <stdio.h>
#include <time.h>

#include "../testarr.h"

int main() {
  int toBeSearched;
  printf("Enter item to be searched: ");
  scanf("%d", &toBeSearched);

  clock_t start_time = clock();
  int pos = -1;
  for (int i = 0; i < 1000; i++) {
    if(toBeSearched == arr[i]) {
      pos = i+1;
      break;
    }
  }

  double elapsed_time = (double)(clock() - start_time)/CLOCKS_PER_SEC;
  printf("found at pos: %d\n", pos);
  printf("Done in %lf seconds.\n", elapsed_time);
  return 0;
}
