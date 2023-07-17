#include <stdio.h>
#include <stdlib.h>

int *stack, size;
int top = -1;

void push() {
  if (top == size - 1) {
    printf("Stack overflow\n");
    return;
  }
  int data;
  printf("Enter data: ");
  scanf("%d", &data);
  stack[++top] = data;
}

void pop() {
  if (top == -1) {
    printf("Stack underflow\n");
    return;
  }
  printf("Popped %d\n", stack[top]);
  top--;
}

void display() {
  if (top == -1) {
    printf("Stack empty.\n");
    return;
  }
  for (int i = 0; i <= top; i++) {
    printf("%d  ", stack[i]);
  }
  printf("\n");
}

int main() {
  printf("Enter stack size: ");
  scanf("%d", &size);
  stack = (int *)calloc(size, sizeof(int));

  int choice;
  printf("1. Push\n"
         "2. Pop\n"
         "3. Display\n"
         "4. Exit");
  while (1) {
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("--Push--\n");
      push();
      break;
    case 2:
      printf("--Pop--\n");
      pop();
      break;
    case 3:
      printf("--Display--\n");
      display();
      break;
    case 4:
      printf("Exiting\n");
      free(stack);
      exit(0);
    default:
      printf("Invalid option.\n");
    }
  }

  return 0;
}