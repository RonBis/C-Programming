#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left_child;
  struct node *right_child;
} node;

node *root;

void insert(int val) {
  node *leaf = (node *)malloc(sizeof(node));
  leaf->data = val;

  if (root == NULL) {
    root = leaf;
    return;
  }

  node *tmp = root;
  while ((tmp->left_child != NULL && val < tmp->data) ||
         (tmp->right_child != NULL && val >= tmp->data)) {
    if (val < tmp->data) {
      tmp = tmp->left_child;
    } else {
      tmp = tmp->right_child;
    }
  }

  if (val < tmp->data) {
    tmp->left_child = leaf;
  } else {
    tmp->right_child = leaf;
  }
}

/*  @brief finds any matching node
    @param val
    @returns node*
*/
node *bfs(int val) {
  node *tmp = root;
  while ((tmp->left_child != NULL && val < tmp->data) ||
         (tmp->right_child != NULL && val > tmp->data)) {
    if (val == tmp->data) {
      return (node *)tmp;
    } else if (val < tmp->data) {
      tmp = tmp->left_child;
    } else {
      tmp = tmp->right_child;
    }
  }

  return NULL;
}

int main() {
  int tree_arr[] = {10, 20, 15, 40, 8, 12, 34};

  for (int i = 0; i < sizeof(tree_arr) / sizeof(tree_arr[0]); i++) {
    insert(tree_arr[i]);
  }
  int data = bfs(8)->data;

  printf("Found %d.", bfs(8)->data);

  return 0;
}
