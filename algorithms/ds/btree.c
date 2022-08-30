#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct NODE {
  struct NODE *left_child;
  int data;
  struct NODE *right_child;
};
typedef struct NODE node;

node *root = NULL;

node *traverse(node *new_node, bool should_display) {
  node *tmp = root;

  if (tmp->left_child != NULL && tmp->right_child != NULL) {
    if (new_node->data >= tmp->data) {
      should_display ? printf("left:%d root:%d right:%d", tmp->left_child->data,
                              tmp->data, tmp->right_child->data)
                     : false;

      tmp = tmp->right_child;
      traverse(tmp, should_display);
    } else {
      should_display ? printf("left:%d root:%d right:%d", tmp->left_child->data,
                              tmp->data, tmp->right_child->data)
                     : false;

      tmp = tmp->left_child;
      traverse(tmp, should_display);
    }
  }

  return tmp;
}

void insert() {
  node *new_node = (node*)malloc(sizeof(node));
  int val;

  while (1) {
    printf("Val to insert: ");
    scanf("%d", &val);

    new_node->left_child = NULL;
    new_node->data = val;
    new_node->right_child = NULL;

    traverse(new_node, true);
  }
}

void display(node *root) {
  // traverse(root, )
}

int main() {
  // {10, 20, 30, 4, 17, 25, 31}
  root = NULL;
  insert();

  return 0;
}
