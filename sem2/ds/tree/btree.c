#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left, *right;
} node;

node *root = NULL;

void createNode(node **nd) {
	node* ptr = (node *)malloc(sizeof(node));
	
	printf("Data? ");
 	scanf("%d", &ptr->data);
	ptr->left = NULL;
	ptr->right = NULL;
	
	*nd = ptr;
	
	int ch;
	printf("%d has left child (1/0)? ", (*nd)->data);
	scanf("%d", &ch);
	if(ch == 1) {
		createNode(&(*nd)->left);
	}
	
	printf("%d has right child (1/0)? ", (*nd)->data);
	scanf("%d", &ch);
	if(ch == 1) {
		createNode(&(*nd)->right);
	}
}

void inOrder(node *root) {
	if(root == NULL) return;
	
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void preOrder(node *root) {
	if (root == NULL) return;
	
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node *root) {
	if (root == NULL) return;
	
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

int main() {
	createNode(&root);
	
	if(root == NULL) {
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
