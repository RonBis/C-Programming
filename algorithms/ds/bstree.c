#include <stdio.h>
#include <stdlib.h>

struct NODE {
  struct NODE *left_child;
  int data;
  struct NODE *right_child;
};
typedef struct NODE node;

node *root = NULL;

void insert(int val) {
  node *leaf = (node *)malloc(sizeof(node));
  leaf->data = val;
  leaf->left_child = NULL;
  leaf->right_child = NULL;

  node *tmp = root;

  if(root == NULL) {
    root = leaf;
    return;
  }
  while ((tmp->left_child != NULL && val < tmp->data) || (tmp->right_child != NULL && val > tmp->data)) {
    if(val < tmp->data) {
      tmp = tmp->left_child;
    } else {
      tmp = tmp->right_child;
    }
  }

  if(val < tmp->data){
    tmp->left_child = leaf;
  }else{
    tmp->right_child = leaf;
  }
}

void display() {
  // code
}

void delete () {
  // code
}

int main() {
  // {10, 20, 30, 4, 17, 25, 31}
  printf("## Binary tree ##\n1) Insert, 2) Display, 3) Delete, 4) Exit\n\n");

  while (1) {
    int choice;
    printf("Choice> ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int val;
      printf("Val to insert: ");
      scanf("%d", &val);
      insert(val);
      break;
    }
    case 2:
      display();
      break;
    case 3:
      delete ();
      break;
    case 4:
      return 0;
    default:
      printf("Invalid choice!\n");
      break;
    }
  }

  return 0;
}
