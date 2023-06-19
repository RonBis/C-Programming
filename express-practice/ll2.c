#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} node;

node *head = NULL;
int nodeCount = 0;

node *createNode(int data) {
  node *nd = (node *)malloc(sizeof(node));
  *nd = (node){.data = data, .prev = NULL, .next = NULL};
  return nd;
}

void insertAtBeg(int data) {
  node *new = createNode(data);
  new->next = head;
  head = new;
  nodeCount++;
}
void insertAtEnd(int data) {
  if (head == NULL) {
    insertAtBeg(data);
  }
  node *tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  node *new = createNode(data);
  new->prev = tmp;
  tmp->next = new;
  nodeCount++;
}
void insertAtPos(int data, int pos) {
  if (pos < 1 || pos > nodeCount + 1) {
    printf("Invalid position.\n");
    return;
  }

  if (pos == 1)
    return insertAtBeg(data);
  else {
    node *tmp = head, *new = createNode(data);
    int count = 1;
    while (count < pos - 1) {
      tmp = tmp->next;
      count++;
    }
    node *after = tmp->next;
    tmp->next = new;
    new->next = after;
    nodeCount++;
  }
}

void deleteFromStart() {
  if (head == NULL)
    return;
  node *del = head;
  head = head->next;
  free(del);
  nodeCount--;
}
void deleteFromEnd() {
  if (head == NULL)
    return;

  if (head->next == NULL)
    return deleteFromStart();

  node *tmp = head;
  while (tmp->next->next != NULL) {
    tmp = tmp->next;
  }
  node *del = tmp->next;
  tmp->next = del->next;
  free(del);
  nodeCount--;
}
void deleteFromPos(int pos) {
  if (pos < 1 || pos > nodeCount) {
    printf("Invalid position.\n");
    return;
  }

  if (pos == 1)
    return deleteFromStart();

  node *tmp = head;
  int count = 1;
  while (count < pos - 1) {
    tmp = tmp->next;
    count++;
  }
  node *del = tmp->next;
  tmp->next = del->next;
  free(del);
  nodeCount--;
}

void display() {
  if (head == NULL) {
    printf("No nodes in linked list");
    return;
  }

  node *tmp = head;
  while (tmp != NULL) {
    printf("%d  ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

int getUserInput() {
  int data;
  printf("Data: ");
  scanf("%d", &data);
  return data;
}

int main() {
  int ch;

  while (1) {
    printf("\n1.Insert at beginning\n"
           "2.Insert at end\n"
           "3.Insert at given position\n"
           "4.Delete from start\n"
           "5.Delete from end\n"
           "6.Delete from given position\n"
           "7.Display\n"
           "8.Exit\n");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      insertAtBeg(getUserInput());
      break;
    case 2:
      insertAtEnd(getUserInput());
      break;
    case 3: {
      int pos;
      printf("Enter position for new data to be inserted: ");
      scanf("%d", &pos);
      insertAtPos(getUserInput(), pos);
      break;
    }
    case 4:
      deleteFromStart();
      break;
    case 5:
      deleteFromEnd();
      break;
    case 6: {
      int pos;
      printf("Enter position for data deletion: ");
      scanf("%d", &pos);
      deleteFromPos(pos);
      break;
    }
    case 7:
      display();
      break;
    case 8:
      exit(EXIT_SUCCESS);
      break;
    }
  }

  return 0;
}
