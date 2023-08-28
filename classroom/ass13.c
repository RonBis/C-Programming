#include <stdio.h>
#include <stdlib.h>

int *stack1, *stack2, size;
int top1 = -1, top2 = -1;

void reverse() {
  // pop each value from stack1 and push it to stack2
  while (top1 != -1) {
    stack2[++top2] = stack1[top1--];
  }
}

int main() {
  while (1) {
    printf("Enter stack size: ");
    scanf("%d", &size);
    if (size > 0)
      break;
    else
      printf("Enter valid stack size\n\n");
  }
  stack1 = (int *)calloc(size, sizeof(int));
  stack2 = (int *)calloc(size, sizeof(int));

  printf("Enter the stack:\n");
  for (int i = 0; i < size; i++) {
    printf("Push element %d: ", i);
    scanf("%d", &stack1[++top1]);
  }
  printf("Stack before reversing:\n");
  for (int i = 0; i < size; i++) {
    printf("%d  ", stack1[i]);
  }
  reverse();
  printf("\nReversed stack:\n");
  for (int i = 0; i < size; i++) {
    printf("%d  ", stack2[i]);
  }

  printf("\n");
  return 0;
}
