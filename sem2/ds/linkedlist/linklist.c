#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *next;
} node;

int count(node *head) {
  node *tmp = head;
  int count = 0;
  while (tmp != NULL) {
    tmp = tmp->next;
    count++;
  }
  return count;
}

node *createNode() {
  node *nd = (node *)malloc(sizeof(node));
  nd->next = NULL;

  printf("\nEnter data: ");
  scanf("%d", &nd->data);
  return nd;
}

node *insertAtBeg(node *head) {
  node *nd = createNode();
  nd->next = head;
  head = nd;
  return head;
}

node *insertAtEnd(node *head) {
  if (head == NULL) {
    return insertAtBeg(head);
  } else {
    node *tmp = head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = createNode();
  }
  return head;
}

/// 1 means first position
node *insertAtPos(node *head) {
  int pos;
  printf("\nEnter position for new node: ");
  scanf("%d", &pos);

  int node_count = count(head);
  if (pos < 1 || pos > node_count + 1) {
    printf("Index out of bound.\n");
    return head;
  }

  if (pos == 1) {
    return insertAtBeg(head);
  } else {
    node *tmp = head;
    node *nd = createNode();

    int curr = 1;
    while (tmp != NULL) {
      if (curr == pos - 1) {
        nd->next = tmp->next;
        tmp->next = nd;
        break;
      }
      tmp = tmp->next;
      curr++;
    }
  }
  return head;
}

void display(node *head) {
  if (head == NULL) {
    printf("\nLinked list is empty.\n");
    return;
  };

  printf("\n");
  node *tmp = head;
  while (tmp != NULL) {
    printf("%d\t", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

node *delFromStart(node *head) {
  if (head == NULL) {
    printf("\nLinked list is empty.\n");
    return head;
  };

  node *firstNode = head;
  head = head->next;
  free(firstNode);
  printf("\n");
  return head;
}

node *delFromEnd(node *head) {
  if (head == NULL) {
    printf("\nLinked list is empty.\n");
    return head;
  };

  node *cur = head, *prev = head;
  while (cur != NULL) {
    if (cur->next == NULL) {
      // checking if lastnode is head, then free(head) and make head=NULL
      node *lastNode = cur;
      free(lastNode);
      if (cur == head) {
        head = NULL;
        return head;
      }
      prev->next = NULL;
      break;
    }
    prev = cur;
    cur = cur->next;
    // printf("\nPrevious: %d, Current: %d\n", prev->data, cur->data);
  }

  printf("\n");
  return head;
}

node *delFromPos(node *head) {
  int pos;
  printf("\nEnter position for deleting node: ");
  scanf("%d", &pos);

  int nodeCount = count(head);
  if (pos < 1 || pos > nodeCount) {
    printf("Given position is out of bound.\n");
    return head;
  }

  if (pos == 1) {
    return delFromStart(head);
  }

  node *temp = head;
  int counter = 1;
  // play loop upto one place before the pos
  while (counter < pos - 1) {
    temp = temp->next;
    counter++;
  }
  node *loc = temp->next;
  temp->next = temp->next->next;
  free(loc);

  return head;
}

void concatenate() {
  printf("\nEnter first linklist elements:");
  node *head1 = NULL;
  char ch = 'y';
  while (1) {
    head1 = insertAtEnd(head1);

    printf("Add elements (y/n)? ");
    scanf(" %c", &ch);
    if (ch == 'y')
      continue;
    break;
  }

  node *tail = head1;
  while (tail->next != NULL) {
    tail = tail->next;
  }

  printf("\nEnter second linklist elements:");
  node *head2 = NULL;
  while (1) {
    head2 = insertAtEnd(head2);

    printf("Add elements (y/n)? ");
    scanf(" %c", &ch);
    if (ch == 'y')
      continue;
    break;
  }

  tail->next = head2;

  printf("\nMerged linklist:");
  display(head1);

  free(head1);
}

void search(node *head) {
  if (head == NULL) {
    printf("\nLinked list is empty.\n");
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

node *reverseLinklist(node *head) {
  if (head == NULL)
    return head;

  // allocate mem for no of nodes in linkedlist
  int counter;
  int nodeCount = counter = count(head);
  node *arr[nodeCount], *tmp = head;

  while (tmp != NULL) {
    arr[--counter] = tmp;
    tmp = tmp->next;
  }

  head = arr[0];
  while (counter < nodeCount - 1) {
    arr[counter]->next = arr[counter + 1];
    counter++;
  }
  arr[counter]->next = NULL;
  return head;
}

int main() {
  int choice;
  node *head = NULL;

  while (1) {
    printf("\nEnter choice:\n"
           "1. Insert at beginning\n"
           "2. Insert at end\n"
           "3. Insert at pos\n"
           "4. Display\n"
           "5. Delete from start\n"
           "6. Delete from end\n"
           "7. Delete at pos\n"
           "8. Concatenate another linked list\n"
           "9. Search element\n"
           "10. Reverse linked list\n"
           "11. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("--Insert at beginning--");
      head = insertAtBeg(head);
      break;
    case 2:
      printf("--Insert at end--");
      head = insertAtEnd(head);
      break;
    case 3:
      printf("--Insert at position--");
      head = insertAtPos(head);
      break;
    case 4:
      printf("--Display--");
      display(head);
      break;
    case 5:
      printf("--Delete from beginning--");
      head = delFromStart(head);
      break;
    case 6:
      printf("--Delete from end--");
      head = delFromEnd(head);
      break;
    case 7:
      printf("--Delete from pos--");
      head = delFromPos(head);
      break;
    case 8:
      printf("--Concatenate two linklist--");
      concatenate();
      break;
    case 9:
      printf("--Search element--");
      search(head);
      break;
    case 10:
      printf("--Reverse linklist--");
      head = reverseLinklist(head);
      break;
    case 11:
      exit(0);
    default:
      printf("Invalid option.\n");
    }
  }

  free(head);
  return 0;
}
