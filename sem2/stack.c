#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *next;
} node;
node *head = NULL;

node *createNode() {
  node *nd = (node *)malloc(sizeof(node));
  nd->next = NULL;

  printf("\nEnter data: ");
  scanf("%d", &nd->data);
  return nd;
}

void push() {
  if (head == NULL) {
    node *nd = createNode();
  	nd->next = head;
  	head = nd;
  } else {
    node *tmp = head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = createNode();
  }
}

void pop() {
  if (head == NULL) {
    printf("\nLinked list is empty.\n");
    return;
  };

  node *cur = head, *prev = head;
  while (cur != NULL) {
    if (cur->next == NULL) {
      // checking if lastnode is head, then free(head) and make head=NULL
      node *lastNode = cur;
      free(lastNode);
      if (cur == head) {
        head = NULL;
        return;
      }
      prev->next = NULL;
      break;
    }
    prev = cur;
    cur = cur->next;
  }
}

void display() {
	if(head == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	
	node *tmp = head;
	while(tmp != NULL) {
		printf("%d  ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {
	int choice;
	
	while(1) {
		printf("\nEnter choice:\n"
           "1. Push\n"
           "2. Pop\n"
           "3. Display\n"
           "4. Exit\n");
    	scanf("%d", &choice);
    	
    	switch(choice) {
    		case 1:
    			printf("Push:\n");
    			push();
    			break;
    		case 2:
    			printf("Pop:\n");
    			pop();
    			break;
    		case 3:
    			printf("Display:\n");
    			display();
    			break;
    		case 4:
    			exit(0);
    		default:
      			printf("Invalid option.\n");
    	}
	}
	
	return 0;
}

