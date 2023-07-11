#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *prev, *next;
} node;

node *head = NULL;

int count(node *head) {
  node *tmp = head;
  int count = 0;
  while (tmp != NULL) {
    tmp = tmp->next;
    count++;
  }
  return count;
}

node *create(int data, node *prev, node *next) {
  node *nd = (node *)malloc(sizeof(node));
  nd->data = data;
  nd->prev = prev;
  nd->next = next;
  return nd;
}

int getInput() {
  int data;
  printf("Enter data: ");
  scanf("%d", &data);
  return data;
}

void insertStart() {
  int data = getInput();

  if (head == NULL) {
    head = create(data, NULL, NULL);
    return;
  }

  node *nd = create(data, NULL, head);
  head->prev = nd;
  head = nd;
}

void insertEnd() {
  int data = getInput();
  if (head == NULL) {
    head = create(data, NULL, NULL);
    return;
  }

  node *tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = create(data, tmp, NULL);
}

/// 1 means first position
void insertAtPos() {
  int pos;
  printf("\nEnter position for new node: ");
  scanf("%d", &pos);

  int node_count = count(head);
  if (pos < 1 || pos > node_count + 1) {
    printf("Index out of bound.\n");
    return;
  }

  if (pos == 1) {
    insertStart();
  } else if (pos == node_count + 1) {
    insertEnd();
  } else {
    int data = getInput();
    int curr = 1;
    node *tmp = head;

    // iterate upto given position minus 1
    while (curr != pos - 1) {
      tmp = tmp->next;
      curr++;
    }

    node *nd = create(data, tmp, tmp->next);
    nd->next->prev = nd;
    tmp->next = nd;
  }
}

void delStart() {
  if (head == NULL) {
    printf("Linked list is empty.\n");
    return;
  }
  node *loc = head;
  head = head->next;
  free(loc);
}

void delEnd() {
  if (head == NULL) {
    printf("Linked list is empty.\n");
    return;
  };

  if (head->next == NULL) {
    free(head);
    head = NULL;
    return;
  }

  node *tmp = head->next;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  node *loc = tmp;
  loc->prev->next = NULL;
  free(loc);

  printf("\n");
}

void search() {
  if (head == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  int data;
  printf("\nEnter data to be searched: ");
  scanf("%d", &data);
  int pos = -1;

  int counter = 1;
  node *tmp = head;
  while (tmp != NULL) {
    if (tmp->data == data) {
      printf("Found at position: %d\n", counter);
      pos = counter;
      break;
    }
    tmp = tmp->next;
    counter++;
  }
  if (pos == -1) {
    printf("Item not found.\n");
  }
}

void display() {
  if (head == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  node *tmp = head;
  while (tmp != NULL) {
    printf("%d  ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {
  int choice;

  printf("1. Insert at beginning\n"
         "2. Insert at end\n"
         "3. Insert at pos\n"
         "4. Display\n"
         "5. Delete from start\n"
         "6. Delete from end\n"
         "7. Search\n"
         "8. Exit\n");
  while (1) {
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("--Insert at beginning--\n");
      insertStart();
      break;
    case 2:
      printf("--Insert at end--\n");
      insertEnd();
      break;
    case 3:
      printf("--Insert at position--\n");
      insertAtPos();
      break;
    case 4:
      printf("--Display--\n");
      display();
      break;
    case 5:
      printf("--Delete from beginning--\n");
      delStart();
      break;
    case 6:
      printf("--Delete from end--\n");
      delEnd();
      break;
    case 7:
      printf("--Search--\n");
      search();
      break;
    case 8:
      exit(0);
    default:
      printf("Invalid option.\n");
    }
  }

  printf("\n");

  return 0;
}
