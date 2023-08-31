#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
} node;

node *findInorderSuccessor(node *nd) {
  node *t = nd;
  while (t != NULL && t->left != NULL) {
    t = t->left;
  }
  return t;
}

node *createNode(int data) {
  node *t = (node *)malloc(sizeof(node));
  t->data = data;
  t->left = NULL;
  t->right = NULL;
  return t;
}

node *insert(node *root, int data) {
  // if tree is empty
  if (root == NULL)
    return createNode(data);

  // tree not empty
  if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }

  return root;
}

node *deleteNode(node *root, int data) {
  if (root == NULL)
    return root;

  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (root->data > data) {
    root->right = deleteNode(root->right, data);
  } else {
    // if node has at most 1 child
    if (root->left == NULL) {
      node *tmp = root->right;
      free(root);
      return tmp;
    } else if (root->right == NULL) {
      node *tmp = root->left;
      free(root);
      return tmp;
    }

    // if node has two children
    node *tmp = findInorderSuccessor(root->right);
    root->data = tmp->data;
    root->right = deleteNode(root->right, tmp->data);
  }
  return root;
}

void inorder(node *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  printf("%d  ", root->data);
  inorder(root->right);
}

int main() {
  node *root = NULL;
  int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  for (int i = 0; i < 10; i++) {
    root = insert(root, arr[i]);
  }

  inorder(root);
  root = deleteNode(root, 2);
  printf("\n--- After deleting 2 ---\n");
  inorder(root);

  printf("\n");
  return 0;
}
