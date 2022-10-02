/* doubly linklist with faster access */

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *prev;
  struct NODE *next;
} node;

node *head, *tail;
int node_count = 0;

void insert(int data) {
  if (head == NULL) {
    head = (node *)malloc(sizeof(node));

    head->data = data;
    head->prev = NULL;
    head->next = NULL;

    tail = head;
    node_count++;
    return;
  }

  node *tmp = (node *)malloc(sizeof(node));
  tmp->data = data;
  tmp->prev = tail;
  tmp->next = NULL;

  tail->next = tmp;
  tail = tail->next;

  node_count++;
}

void insertAt(int data, int position) {
  if (position < 0 || position > node_count) {
    printf("Invalid position!");
    return;
  }
  if (head == NULL || position == node_count) {
    insert(data);
    return;
  }

  int counter = 0;
  node *tmp = head;
  while (tmp->next != NULL) {
    if (counter == position) {
      break;
    }
    tmp = tmp->next;
    counter++;
  }

  node *new = (node *)malloc(sizeof(node));
  new->data = data;
  new->prev = tmp->prev;
  new->next = tmp;

  if (position == 0) {
    tmp->prev = new;
    new->prev = NULL;
    head = new;
  }

  node *tmp_prev = tmp->prev;
  tmp->prev = new;
  tmp_prev->next = new;

  node_count++;
}

int deleteAt(int position) {
  if (position < 0 || position >= node_count) {
    printf("Invalid position!");
    return ;
  }
}

int main() {
  insert(1);
  insert(2);
  insert(3);

  insertAt(100, 0);
  printf("%d\n", head->data);

  return 0;
}
