#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
  int data;
  struct Node *left_child;
  struct Node *right_child;
} node;

node *root = NULL;

void insertNode(int val) {
  node *leaf = (node *)malloc(sizeof(node));
  leaf->data = val;
  leaf->left_child = NULL;
  leaf->right_child = NULL;

  if(root == NULL) {
    root = leaf;
    return;
  }

  node *tmp = root;
  while((tmp->left_child != NULL && val < tmp->data) || (tmp->right_child != NULL && val>= tmp->data)) {
    if(val < tmp->data) {
      tmp = tmp->left_child;
    } else {
      tmp = tmp->right_child;
    }
  }

  if(val < tmp->data) {
    tmp->left_child = leaf;
  } else {
    tmp->right_child = leaf;
  }
}

void heapsort(node *nd, int *_sorted) {
  static int index = 0;

  if(nd == NULL)
    return;
  else {
    heapsort(nd->left_child, _sorted);
    _sorted[index++] = nd->data;
    heapsort(nd->right_child, _sorted);
  }
}

int main() {
  int arr[SIZE] = {33, 37, 9, 47, 35, 24, 12, 0, 19, 20};
  for (int i = 0; i < SIZE; i++) {
    insertNode(arr[i]);
  }

  int sorted[SIZE];
  heapsort(root, sorted);
  for (int i = 0; i < SIZE; i++) {
    printf("%d\t", sorted[i]);
  }

  printf("\n");

  return 0;
}
