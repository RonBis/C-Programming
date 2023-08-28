#include <stdio.h>
#include <stdlib.h>

int *stack1, *queue, size;
int top1 = -1, front = -1, rear = -1;

void push(int data) {
  if (top1 == size - 1) {
    printf("Stack overflow\n");
    return;
  }
  stack1[++top1] = data;
}

int pop() {
  if (top1 == -1) {
    printf("Stack underflow\n");
    return;
  }
  return stack1[top1--];
}

void enqueue(int data) {
  if (rear == size) {
    printf("Queue overflow\n");
    return;
  }
  if (front == -1 && rear == -1) {
    front = 0;
  }
  queue[++rear] = data;
}

int dequeue() {
  if (front > rear) {
    printf("Queue underflow\n");
    return;
  }
  return queue[front++];
}

void reverse() {
  while (top1 != -1) {
    enqueue(pop());
  }
  while (top1 != size - 1) {
    push(dequeue());
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
  queue = (int *)calloc(size, sizeof(int));

  printf("Enter the stack:\n");
  for (int i = 0; i < size; i++) {
    int data;
    printf("Push element %d: ", i);
    scanf("%d", &data);
    push(data);
  }
  printf("Stack before reversing:\n");
  for (int i = 0; i < size; i++) {
    printf("%d  ", stack1[i]);
  }
  reverse();
  printf("\nReversed stack:\n");
  for (int i = 0; i < size; i++) {
    printf("%d  ", stack1[i]);
  }

  printf("\n");
  return 0;
}
