#include <stdio.h>
#include <stdlib.h>

int *queue, size;
int front = -1, rear = -1;

void enqueue() {
  if(rear == size) {
  	printf("Queue overflow\n");
  	return;
  }

  if(front == -1 && rear == -1) {
  	front = 0, rear = 0;
  }

  int data;
  printf("Enter data: ");
  scanf("%d", &data);

  queue[rear++] = data;
}

void dequeue() {
  if (front >= rear) {
    printf("Queue underflow\n");
    return;
  }

  printf("Dequeued %d\n", queue[front]);
  front++;
}

void display() {
  if (front >= rear) {
    printf("Queue is empty.\n");
    return;
  }

  int i;
  for (i = front; i < rear; i++) {
    printf("%d  ", queue[i]);
  }
  printf("\n");
}

int main() {
  printf("Enter queue size: ");
  scanf("%d", &size);

  queue = (int *)calloc(size, sizeof(int));
  int choice;

  while (1) {
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