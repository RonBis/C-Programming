#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
} node;
node **stack;
int count;

void createNode(node **nd) {
  node *ptr = (node *)malloc(sizeof(node));

  printf("Data? ");
  scanf("%d", &ptr->data);
  ptr->left = NULL;
  ptr->right = NULL;

  *nd = ptr;

  int ch;
  printf("%d has left child (1/0)? ", (*nd)->data);
  scanf("%d", &ch);
  if (ch == 1) {
    createNode(&(*nd)->left);
  }

  printf("%d has right child (1/0)? ", (*nd)->data);
  scanf("%d", &ch);
  if (ch == 1) {
    createNode(&(*nd)->right);
  }
}

void inOrder(node *root) {
  if (root == NULL)
    return;

  inOrder(root->left);
  printf("%d ", root->data);
  inOrder(root->right);
}

void preOrder(node *root) {
  if (root == NULL)
    return;

  printf("%d ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(node *root) {
  if (root == NULL)
    return;

  postOrder(root->left);
  postOrder(root->right);
  printf("%d ", root->data);
}

int pushToTree(node *nd) { stack[count++] = nd; }
int popFromTree() {
  stack[count - 1] = NULL;
  count--;
}

int createTreeStack() {
  printf("How many nodes: ");
  scanf("%d", &count);

  stack = (node **)malloc(count * sizeof(node *));
  while (1) {
    node *nd = (node *)malloc(sizeof(node));
    printf("Data? ");
    scanf("%d", &nd->data);
    nd->left = NULL;
    nd->right = NULL;

    pushToTree(nd);

    int ch;
    printf("%d has left child (1/0)? ", nd->data);
    scanf("%d", &ch);
    if (ch == 1) {
    }

    printf("%d has right child (1/0)? ", nd->data);
    scanf("%d", &ch);
    if (ch == 1) {
    }
  }
}

int main() {
  node *root;
  createTreeStack();

  if (root == NULL) {
    printf("root is null\n");
  }

  printf("Inorder: ");
  inOrder(root);

  printf("\nPreorder: ");
  preOrder(root);

  printf("\nPostorder: ");
  postOrder(root);

  return 0;
}
