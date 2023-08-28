#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *next;
} node;

node *head = NULL;

node *createNode() {
  node *nd = (node *)malloc(sizeof(node));
  printf("Data: ");
  scanf("%d", &nd->data);
  nd->next = NULL;
  return nd;
}

void enqueue() {
  node *nd = createNode();
  if (head == NULL) {
    head = nd;
    return;
  }

  node *t = head;
  while (t->next != NULL) {
    t = t->next;
  }
  t->next = nd;
}

void dequeue() {
  if (head == NULL) {
    printf("Queue is empty\n");
    return;
  }
  node *loc = head;
  head = head->next;
  free(loc);
}

void display() {
  if (head == NULL) {
    printf("Queue is empty\n");
    return;
  }
  node *t = head;
  while (t != NULL) {
    printf("%d  ", t->data);
    t = t->next;
  }
}

int main() {
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
      printf("--Enqueue--\n");
      enqueue();
      break;
    case 2:
      printf("--Dequeue--\n");
      dequeue();
      break;
    case 3:
      printf("--Display--\n");
      display();
      break;
    case 4:
      printf("Exiting\n");
      exit(0);
    default:
      printf("Invalid option\n");
    }
  }

  return 0;
}
