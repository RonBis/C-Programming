#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

struct NODE {
  int data;
  struct NODE *left_child;
  struct NODE *right_child;
};
typedef struct NODE node;

node *root;
node *alloc(int size) { return (node *)malloc(size * sizeof(node)); }

void insert(int data) {
  node *leaf = alloc(1);
  leaf->data = data;
  leaf->left_child = NULL;
  leaf->right_child = NULL;

  if (root == NULL) {
    root = leaf;
    return;
  }

  node *tmp = root;
  while ((tmp->left_child != NULL && data < tmp->data) ||
         (tmp->right_child != NULL && data >= tmp->data)) {
    if (data < tmp->data) {
      tmp = tmp->left_child;
    } else {
      tmp = tmp->right_child;
    }
  }

  if (data < tmp->data) {
    tmp->left_child = leaf;
  } else {
    tmp->right_child = leaf;
  }
}

int *search(int val) { return (int *)1; }

void delete (int val) {}

int main() {
  printf("## Binary tree ##\n1) Insert, 2) Search, 3) Delete, 4) Exit");

  while (1) {
    int choice;
    printf("\nChoice> ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int data;
      printf("Data to insert: ");
      scanf("%d", &data);

      insert(data);
      break;
    }
    case 2: {
      int val;
      printf("Data to search: ");
      scanf("%d", &val);

      search(val);
      break;
    }
    case 3: {
      int val;
      printf("Data to delete: ");
      scanf("%d", &val);

      delete (val);
      break;
    }
    case 4:
      printf("Exiting!");
      return 0;
    default:
      printf("Invalid choice!");
    }
  }

  return 0;
}
