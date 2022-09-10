#include <stdio.h>
#include <stdlib.h>

struct NODE {
  struct NODE *parent;
  struct NODE *left_child;
  struct NODE *right_child;
  int data;
};
typedef struct NODE node;

node *root = NULL;
int elementCount = 0;
int treeLevel = 0;

void updateTreeLevel() {
  int allowedChildCount = { 1, 2, 4, 8, 16, 32, 64 };
  if()
}

void insert(int val) {
  elementCount++;

  node *leaf = (node *)malloc(sizeof(node));
  leaf->data = val;
  leaf->left_child = NULL;
  leaf->right_child = NULL;

  node *tmp = root;

  if(root == NULL) {
    root = leaf;
    updateTreeLevel();
    return;
  }
  while() {

  }
}


int main() {
  printf("## AVL Tree ##\n1) Insert, 2) Exit\n\n");

  while (1) {
    int choice;
    printf("Choice> ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int val;
      printf("Value to insert: ");
      scanf("%d", val);

      insert(val);
      break;
    }
    case 2:
      return 0;
    default:
      printf("Invalid choice!\n");
      break;
    }
  }

  return 0;
}
