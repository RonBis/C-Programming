#include <stdio.h>
#include <stdlib.h>

int *stack = NULL;
int max_size = 0;
int top = -1;

void push(int data) {
  if (top == max_size - 1) {
    printf("Stack reached maximum size\n");
    return;
  }
  stack[++top] = data;
}

void pop() {
  if (top == -1) {
    printf("Cannot pop from empty array\n");
    return;
  }
  top--;
}

void display() {
  if (top == -1) {
    printf("Stack is empty\n");
    return;
  }
  for (int i = 0; i <= top; i++) {
    printf("%d  ", stack[i]);
  }
  printf("\n");
}

int main() {
  printf("Enter max length of stack: ");
  scanf("%d", &max_size);

  stack = (int *)calloc(max_size, sizeof(int));

  int choice;
  while (1) {
    printf("1.Push, 2.Pop, 3.Display, 4.Exit\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int data;
      printf("Data: ");
      scanf("%d", &data);
      push(data);
      break;
    }
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(EXIT_SUCCESS);
      break;
    default:
      printf("Invalid choice.\n");
    }
  }

  return 0;
}
