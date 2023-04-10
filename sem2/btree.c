#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left, *right;
} node;

node *root;

void createNode(node *nd) {
	nd = (node *)malloc(sizeof(node));
	nd->data = 9;
	nd->left = NULL;
	nd->right = NULL;
	
// 	printf("Data? ");
// 	scanf("%d", &nd->data);
	
	return;
	
	int ch;
	printf("%d has left child (1/0)? ", nd->data);
	scanf("%d", &ch);
	if(ch == 1) {
		createNode(nd->left);
	}
	
	printf("%d has right child (1/0)? ", nd->data);
	scanf("%d", &ch);
	if(ch == 1) {
		createNode(nd->right);
	}
}

void inOrder(node *root) {
	printf("%d", root->data);
	if(root == NULL) return;
	
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

int main() {
	createNode(root);
	printf("%d", root->data);
	inOrder(root);
	return 0;
}
