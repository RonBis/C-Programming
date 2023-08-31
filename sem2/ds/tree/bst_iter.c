#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int data;
  struct NODE *right;
  struct NODE *left;
};

typedef struct NODE node;

void insertNode(node *root) {
  node *temp = root;
  int d;
  printf("Enter the number");
  scanf("%d", &d);
  while (temp != NULL) {
    printf("current node: %d\n", temp->data);
    if (temp->data > d) {
      if (temp->left == NULL) {
        temp->left = (node *)malloc(sizeof(node));
        temp = temp->left;
        break;
      } else
        temp = temp->left;
    }
    if (temp->data < d) {
      if (temp->right == NULL) {
        temp->right = (node *)malloc(sizeof(node));
        temp = temp->right;
        break;
      } else
        temp = temp->right;
    }
  }
  temp->data = d;
}

void inOrder(node *root) {
  if (root == NULL)
    return;

  inOrder(root->left);
  printf("%d ", root->data);
  inOrder(root->right);
}

void main() {
  node *root;
  int k = 1;
  root = (node *)malloc(sizeof(node));
  printf("Enter a number \n");
  scanf("%d", &root->data);
  //	root->parent = NULL;
  while (k) {
    int n;
    printf("Enter 1 to Enter data \n Enter 2 to exit\n Enter 3 to display "
           "inorder");
    scanf("%d", &n);
    switch (n) {
    case 1:
      insertNode(root);
      break;
    case 2:
      k = 0;
      break;
    case 3:
      inOrder(root);
      printf("\n");
    }
  }
}
