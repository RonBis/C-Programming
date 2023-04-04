#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE *next;
} node;
node* head = NULL;

node* createNode() {
	node* nd = (node*)malloc(sizeof(node));
	nd->next = NULL;
	
	printf("\nEnter data: ");
	scanf("%d", &nd->data);
	return nd;
}

void insertAtBeg() {
	node *nd = createNode();
	nd->next = head;
	head = nd;
}

void insertAtEnd() {
	if(head == NULL) {
		insertAtBeg();
	} else {
		node *tmp = head;
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = createNode();
	}
}

void insertAtPos() {
	
}

void display() {
	if(head == NULL) {
		printf("\nLinked list is empty.\n");
		return;
	};
	
	printf("\n");
	node *tmp = head;
	while(tmp != NULL) {
		printf("%d\t", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void count() {
	int count = 0;
	
	node *tmp = head;
	while(tmp != NULL)  {
		tmp = tmp->next;
		count++;
	}
	printf("\nnode count: %d\n", count);
}

void delFromStart() {
	if(head == NULL) {
		printf("\nLinked list is empty.\n");
		return;
	};
	
	node *firstNode = head;
	head = head->next;
	free(firstNode);
}

void delFromEnd() {
	if(head == NULL) {
		printf("\nLinked list is empty.\n");
		return;
	};
	
	node *cur = head, *prev = head;
	while(cur != NULL) {
		if(cur->next == NULL) {
			// checking if lastnode is head, then free(head) and make head=NULL
			node *lastNode = cur;
			free(lastNode);
			if(cur == head) {
				head = NULL;
				return;
			}
			break;
		}
		prev = cur;
		cur = cur->next;
//		printf("\nPrevious: %d, Current: %d\n", prev->data, cur->data);
	}
	
	printf("\n");
}

int main() {
	int choice;
	
	while(1) {
		printf("\nEnter choice:\n"
				"1. Insert at beginning\n"
				"2. Insert at end\n"
				"3. Insert at pos\n"
				"4. Display\n"
				"5. Count nodes\n"
				"6. Delete from start\n"
				"7. Delete from end\n"
				"8. Exit\n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("--Insert at beginning--");
				insertAtBeg();
				break;
			case 2:
				printf("--Insert at end--");
				insertAtEnd();
				break;
			case 3:
				printf("--Insert at position--");
				insertAtPos();
				break;
			case 4:
				printf("--Display--");
				display();
				break;
			case 5:
				printf("--Count--");
				count();
				break;
			case 6:
				printf("--Delete from beginning--");
				delFromStart();
				break;
			case 7:
				printf("--Delete from end--");
				delFromEnd();
				break;
			case 8:
				exit(0);
			default:
				printf("Invalid option.\n");
		}
	}
	
	return 0;
}

