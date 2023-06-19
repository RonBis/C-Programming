#include <stdio.h>
#include <stdlib.h>

int *queue = NULL;
int max_size = 0;
int front = -1, rear = -1;

void enqueue(int data) {
  if (rear == max_size - 1) {
    printf("Queue is full\n");
    return;
  }
  if (front == -1)
    front = 0;
  queue[++rear] = data;
}

void dequeue() {
  if (rear == -1) {
    printf("Cannot dequeue from empty queue\n");
    return;
  }
  printf("Dequeued %d\n", queue[rear]);
  rear--;
  if (rear == -1)
    front--;
}

void display() {
  if (front == -1) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = 0; i <= rear; i++) {
    printf("%d  ", queue[i]);
  }
  printf("\n");
}

int main() {
  printf("Enter max length of queue: ");
  scanf("%d", &max_size);

  queue = (int *)calloc(max_size, sizeof(int));

  int choice;
  while (1) {
    printf("1.Enqueue, 2.Dequeue, 3.Display, 4.Exit\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int data;
      printf("Data: ");
      scanf("%d", &data);
      enqueue(data);
      break;
    }
    case 2:
      dequeue();
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

  free(queue);
  return 0;
}
