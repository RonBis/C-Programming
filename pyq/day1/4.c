#include <stdio.h>
#include <stdlib.h>

int main() {
  int r1, c1, r2, c2, i, j, k;
  printf("Enter row and column for first matrix (mxn): ");
  scanf("%dx%d", &r1, &c1);
  printf("Enter row and column for second matrix (mxn): ");
  scanf("%dx%d", &r2, &c2);
  if(c1 != r2) printf("multiplication not possible");
  else {
    int A[r1][c1],B[r2][c2],mul[r1][c2];
    printf("Enter first matrix elements \n");    
    for(int i=0;i<r1;i++)    
    {    
        for(int j=0;j<c1;j++)    
        {    
            scanf("%d",&A[i][j]);    
        }    
    }
    /*printf("Enter second matrix elements \n");    
    for(int i=0;i<r2;i++)    
    {    
        for(int j=0;j<c2;j++)    
        {    
            scanf("%d",&B[i][j]);
        }    
    }
    for(i=0;i<r1;i++) {
      for(j=0;j<c2;j++) {
        mul[i][j] = 0;
        for(k=0;k<c1;k++) {
          mul[i][j]+= A[i][k] * B[k][j];
        }
      }
    }*/
    int trans[c1][r1];
    for(i=0;i<c1;i++) {
      for(j=0;j<r1;j++) {
        trans[i][j]= A[j][i];
      }
      printf("\n");
    }
    printf("transposed matrix\n");     
    for(int i=0;i<c1;i++)    
    {    
        for(int j=0;j<r1;j++)    
        {    
            printf("%d  ",trans[i][j]);    
        }    
        printf("\n");    
    } 
  }
  return 0;
}



















/*typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *createnode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node *insert(node *root, int data)
{
    if (root == NULL)
        return createnode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // If the node is with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        // struct node *temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        // root->data = temp->data;

        // Delete the inorder successor
        // root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void display(node *root)
{
    // inorder
    if(root != NULL)
    {
        display(root->left);
        printf("%d", root->data);
        display(root->right);
    }
}

int main()
{
    node *root = NULL;
    int a;
    int ch = 1;
    while (ch == 1)
    {
        printf("Enter node data: ");
        scanf("%d", &a);
        root = insert(root, a);
        printf("Enter '1' to continue or '0' to stop: ");
        scanf("%d  ", &ch);
    }

    display(root);
    return 0;
}*/