#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

node *createNode(int data) {
  node *nd = (node*)malloc(sizeof(node));
  nd->data = data;
  nd->next = NULL;
}

node *insert(node *head, int data) {
  if(head == NULL) {
    head = createNode(data);
    return head;
  }

  node *t = head;
  while(t->next != NULL) {
    t = t->next;
  }
  t->next = createNode(data);
  return head;
}

void display(node *head) {
  node *t = head;
  if(t == NULL) {
    printf("Empty list\n");
    return;
  }

  while(t != NULL) {
    printf("%d -> ", t->data);
    t = t->next;
  }
  printf("\n");
}

void reversePrint(node *head) {
  // base case
  if(head == NULL) return;

  reversePrint(head->next);
  printf("%d <- ", head->data);
}

int main() {
  node *head = NULL;
  // 1 -> insert, 2 -> reverse, 3 -> count, 4 -> display, 0 -> exit
  while(1) {
    int ch;
    printf("> ");
    scanf("%d", &ch);

    switch(ch) {
      case 1: {
        int data;
        printf("val: ");
        scanf("%d", &data);
        head = insert(head, data);
        break;
      }
      case 2:
        reversePrint(head);
        printf("\n");
        break;
      case 3:
        // count(head);
        break;
      case 4:
        display(head);
        break;
      case 0:
        exit(EXIT_SUCCESS);
      default:
        printf("Invalid choice\n");
        break;
    }

  }

  return 0;
}
