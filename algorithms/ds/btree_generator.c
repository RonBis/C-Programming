#include <stdio.h>
#include <stdlib.h>

/*
 * preorder > root, left, right
 * inorder  > left, root, right
 */

#define SIZE 9

struct NODE {
  struct NODE *left_child;
  int data;
  struct NODE *right_child;
};
typedef struct NODE node;

node *root = NULL;
int inorderSet[SIZE] = {7, 10, 11, 12, 13, 14, 15, 16, 18};
int preorderSet[SIZE] = {14, 12, 10, 7, 11, 13, 16, 15, 18};

getIndex(int *set, int val) {
  for (int i = 0; i < SIZE; i++) {
    if (set[i] == val)
      return i;
  }
}

void generateTree(node *nd, int inStart, int inEnd, int preStart) {
  node *leaf = (node *)malloc(sizeof(node));
  leaf->data = preorderSet[preStart];
  leaf->left_child = NULL;
  leaf->right_child = NULL;

  nd = leaf;

  int partitionIndex = getIndex(inorderSet, preorderSet[preStart]);
  generateTree(nd->left_child, 0, partitionIndex - 1, preStart++);
  generateTree(nd->right_child, partitionIndex + 1, , preStart++);
}

int main() {

  generateTree(root, 0, 0);

  return 0;
}
