#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define e(a) a + 65
#define V 5

typedef struct Node {
    char name;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* nd = (Node*)malloc(sizeof(Node));
    nd->name = data;
    nd->next = NULL;
    return nd;
}

void insertNode(Node** head, char data) {
    Node* nd = createNode(data);
    nd->next = *head;
    *head = nd;
}

int main() {
    Node* arrlist[V];
    char ch;
    
    for (int i = 0; i < V; i++) {
        arrlist[i] = NULL;
    }
    
    printf("-- Enter adjacent vertices --\n");
    for (int i = 0; i < V; i++) {
        printf(
            "Vertex %c (Enter X to stop): ",
            e(i));
        while (1) {
            scanf(" %c", &ch);
            if (toupper(ch) == 'X') break;
            insertNode(&arrlist[i], ch);
        }
    }
    printf("\nAdjacency list for given graph:\n");
    for (int i = 0; i < V; i++) {
        Node* current = arrlist[i];
        printf("Vertex %c: ", e(i));
        while (current != NULL) {
            printf("%c ", current->name);
            current = current->next;
        }
        printf("\n");
    }
    return 0;
}