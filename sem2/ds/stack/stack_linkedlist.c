#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *next;
} node;
node *head = NULL;

node *createNode() {
  node *nd = (node *)malloc(sizeof(node));
  nd->next = NULL;

  printf("\nEnter data: ");
  scanf("%d", &nd->data);
  return nd;
}

void push() {
  node *nd = createNode();
  nd->next = head;
  head = nd;
}

void pop() {
  if (head == NULL) {
    printf("\nStack is empty.\n");
    return;
  };
  node *loc = head;
  head = head->next;
  printf("\nPopped %d\n", loc->data);
  free(loc);
}

void display() {
  if (head == NULL) {
    printf("\nStack is empty.\n");
    return;
  }
  node *tmp = head;
  while (tmp != NULL) {
    printf("\n%d", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {
  int choice;
  printf("1. Push\n"
         "2. Pop\n"
         "3. Display\n"
         "4. Exit\n");
  while (1) {
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("--Push--");
      push();
      break;
    case 2:
      printf("--Pop--");
      pop();
      break;
    case 3:
      printf("--Display--");
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid option.\n");
    }
  }
  return 0;
}