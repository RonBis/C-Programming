#include <stdio.h>
#include <stdlib.h>

int *queue, size;
int front = -1, rear = -1;

int checkOverflow() {
  if (rear + 1 == front) {
    printf("Queue overflow\n");
    return 1;
  } else {
    return 0;
  }
}

void enqueue() {
  if (checkOverflow())
    return;

  if (front == -1 && rear == -1) {
    front = rear = 0;
  }

  int data;
  printf("Enter data: ");
  scanf("%d", &data);

  queue[rear] = data;
  rear = (rear + 1) % size;
}

void dequeue() {
  if (front == rear) {
    printf("Queue underflow, resetting queue\n");
    front = rear = -1;
    return -1;
  }

  printf("Dequeued %d\n", queue[front]);
  front = (front + 1) % size;
}

void display() {
  if (checkOverflow())
    return;

  for (int i = front; i < rear; i++) {
    printf("%d ", queue[i]);
  }
}

int main() {
  printf("Enter queue size: ");
  scanf("%d", &size);

  queue = calloc(size, sizeof(int));

  while (1) {
    int choice;
    printf("\nEnter choice:\n"
           "1. Enqueue\n"
           "2. Dequeue\n"
           "3. Display\n"
           "4. Exit\n");
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
