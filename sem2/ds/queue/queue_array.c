#include <stdio.h>
#include <stdlib.h>

int *queue, size;
int front = -1, rear = -1;

void enqueue() {
  if (rear == size - 1) {
    printf("Queue overflow\n");
    return;
  }

  if (front == -1 && rear == -1) {
    front = 0, rear = 0;
  } else {
    rear++;
  }
  printf("Enter data: ");
  scanf("%d", &queue[rear]);
}

void dequeue() {
  if (front > rear || front == -1) {
    printf("Queue underflow\n");
    return;
  }
  printf("Dequeued %d\n", queue[front]);
  front++;
}

void display() {
  if (front == -1) {
    printf("Queue is empty.\n");
    return;
  }
  for (int i = front; i <= rear; i++) {
    printf("%d  ", queue[i]);
  }
  printf("\n");
}

int main() {
  printf("Enter queue size: ");
  scanf("%d", &size);

  queue = (int *)calloc(size, sizeof(int));
  int choice;
  printf("1. Enqueue\n"
         "2. Dequeue\n"
         "3. Display\n"
         "4. Exit\n");
  while (1) {
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enqueue:\n");
      enqueue();
      break;
    case 2:
      printf("Dequeue:\n");
      dequeue();
      break;
    case 3:
      printf("Display:\n");
      display();
      break;
    case 4:
      free(queue);
      exit(0);
    default:
      printf("Invalid option.\n");
    }
  }

  return 0;
}