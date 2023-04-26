#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  bool visited;
  struct Node *left, *right;
} node;

enum insertmode { INSERT_LEFT, INSERT_RIGHT };

// To store the node addresses in stack array
node **stack;
int count = -1;

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

void pushToTree(node *nd) {
  count++;
  stack[count] = nd;
}
int popFromTree() {
  if (count == -1) {
    return -1;
  }

  stack[count] = NULL;
  return count--;
}

void createTreeStack(node *root) {
  int n;
  printf("How many nodes: ");
  scanf("%d", &n);

  // allocate mem for stack
  stack = (node **)malloc(n * sizeof(node *));

  enum insertmode mode;

  while (1) {
    // create new node
    node *new = (node *)malloc(sizeof(node));
    new->left = NULL;
    new->right = NULL;
    new->visited = false;

    if (count == -1) {
      root = new;
    } else {
      if (mode == INSERT_LEFT) {
        stack[count]->left = new;
      } else if (mode == INSERT_RIGHT) {
        stack[count]->right = new;
      }
    }

    if (!stack[count]->visited) {
      // insert data
      printf("Data? ");
      scanf("%d", &new->data);

      // mimic recusrsive binary tree node insertion
      pushToTree(new);
      stack[count]->visited = true;

      char ch;
      printf("\n%d has left child (y/n)? ", stack[count]->data);
      scanf(" %c", &ch);
      if (ch == 'y') {
        mode = INSERT_LEFT;
        continue;
      } else {
        // proceed to the right-child part
      }

      printf("\n%d has right child (y/n)? ", stack[count]->data);
      scanf(" %c", &ch);
      if (ch == 'y') {
        mode = INSERT_RIGHT;
        continue;
      } else {
        // simulate back-tracking
        int status = popFromTree();
        mode = INSERT_RIGHT;
        if (status == -1) {
          // finish tree and exit while loop, when all nodes are popped from
          // stack
          break;
        }
      }
    }
  }
}

int main() {
  node *root;
  createTreeStack(root);

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
