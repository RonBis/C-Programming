#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE *prev, *next;
} node;

node *head = NULL;

node *create(int data, node *prev, node *next) {
	node *nd = (node *)malloc(sizeof(node));
	nd->data = data;
	nd->prev = prev;
	nd->next = next;
	
	return nd;
}

int getInput() {
	int data;
	printf("Enter data: ");
	scanf("%d", &data);
	return data;
}

void insertStart() {
	int data = getInput();
	
	if(head == NULL) {
		head = create(data, NULL, NULL);
		return;
	}
	
	node *nd = create(data, NULL, head);
	head = nd;
}

void insertEnd() {
	int data = getInput();
	
	if(head == NULL) {
		head = create(data, NULL, NULL);
		return;
	}
	
	node *tmp = head;
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = create(data, tmp, NULL);
}

void delStart() {
	if(head == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	
	node *loc = head;
	head = head->next;
	free(loc);
}

void delEnd() {
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
    //		printf("\nPrevious: %d, Current: %d\n", prev->data, cur->data);
  }

  printf("\n");
}

void search() {
	if(head == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	
	int data = getInput();
	int pos = -1;
	
	int counter = 1;
	node *tmp = head;
	while(tmp != NULL) {
		if(tmp->data == data) {
			printf("Found at position: %d\n", counter);
			pos = counter;
			break;
		}
		tmp = tmp->next;
		counter++;
	}
	if(pos == -1) {
		printf("Item not found.\n");		
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

  while (1) {
    printf("\nEnter choice:\n"
           "1. Insert at beginning\n"
           "2. Insert at end\n"
           "3. Insert at pos\n"
           "4. Display\n"
           "5. Count nodes\n"
           "6. Delete from start\n"
           "7. Delete from end\n"
           "8. Search\n"
           "9. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      	printf("--Insert at beginning--\n");
      	insertStart();
      	break;
    case 2:
      	printf("--Insert at end--\n");
      	insertEnd();
      	break;
    case 3:
      	printf("--Insert at position--\n");
      	//insertAtPos();
      	break;
    case 4:
      	printf("--Display--\n");
      	display();
      	break;
    case 5:
      	printf("--Count--");
      	//printf("\nNode count: %d\n", count());
      	break;
    case 6:
      	printf("--Delete from beginning--\n");
      	delStart();
      	break;
    case 7:
      	printf("--Delete from end--\n");
      	delEnd();
      	break;
    case 8:
    	printf("--Search--\n");
    	search();
    	break;
    case 9:
      	exit(0);
    default:
      	printf("Invalid option.\n");
    }
  }
  
  printf("\n");

  return 0;
}


