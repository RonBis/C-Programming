#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

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

  if (root == NULL) {
    root = leaf;
    return;
  }
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

void traverseInorder(node *nd, FILE *fp) {
  if (nd == NULL)
    return;
  else {
    traverseInorder(nd->left_child, fp);
    fprintf(fp, "%d\t", nd->data);
    traverseInorder(nd->right_child, fp);
  }
}

void traversePreorder(node *nd, FILE *fp) {
  if (nd == NULL)
    return;
  else {
    fprintf(fp, "%d\t", nd->data);
    traversePreorder(nd->left_child, fp);
    traversePreorder(nd->right_child, fp);
  }
}

// void traversePostorder(node *nd) {
//   if (nd != NULL) {
//     if (nd->left_child != NULL) {
//       traverseInorder(nd->left_child);
//     }

//     if (nd->right_child != NULL) {
//       traverseInorder(nd->right_child);
//     }

//     printf("%d\t", nd->data);
//   }
// }

void display() {
  FILE *fp;
  fp = fopen("testfile.txt", "a");

  fprintf(fp, "%s", "Inorder > ");
  traverseInorder(root, fp);
  fprintf(fp, "%s", "\n");

  fprintf(fp, "%s", "Preorder > ");
  traversePreorder(root, fp);
  fprintf(fp, "%s", "\n");
  // traversePostorder(root);

  printf("\n");
  fclose(fp);
}

int main() {
  int arr[SIZE] = {14, 7, 4, 11, 13, 17, 53};
  printf("## Binary tree ##\n1) Insert, 2) Display, 3) Delete, 4) Exit\n\n");

  while (1) {
    int choice;
    printf("Choice> ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int val;
      // printf("Val to insert: ");
      // scanf("%d", &val);
      for (int i = 0; i < SIZE; i++) {
        insert(arr[i]);
      }

      // insert(val);
      break;
    }
    case 2:
      display();
      break;
    // case 3: {
    //   int val;
    //   printf("Val to delete: ");
    //   scanf("%d", &val);
    //   delete (val);
    //   break;
    // }
    case 4:
      return 0;
    default:
      printf("Invalid choice!\n");
      break;
    }
  }

  return 0;
}
