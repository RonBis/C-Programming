#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int id;
  int cost;
} node;

int NODE_COUNT;
int **adjacencyMatrix;
int *visited;
int globCost = -1;

node *queue;
int qfront = -1, qrear = -1;

void enQueue(int id) {
  if (qrear == NODE_COUNT - 1)
    printf("\nQueue is Full");
  else {
    if (qfront == -1)
      qfront = 0;
    qrear++;
    queue[qrear] = (node){.id = id, .cost = globCost++};
    printf("\nInserted -> %d", id);
  }
}
void deQueue() {
  if (qfront == -1)
    printf("\nQueue is Empty");
  else {
    printf("\nDeleted : %d", queue[qfront].id);
    qfront++;
    if (qfront > qrear)
      qfront = qrear = -1;
  }
}

void search(node src) {
  for (int i = 0; i < NODE_COUNT; i++) {
    if (adjacencyMatrix[src.id][i] == 1 && src.id != i && visited[i] != 1) {
      printf("%d\t", src.id);
      enQueue(i);
      search(queue[i]);
    }
  }
  deQueue(src);
}

int main() {
  printf("Number of nodes: ");
  scanf("%d", &NODE_COUNT);

  adjacencyMatrix = (int **)calloc(NODE_COUNT, sizeof(int *));
  visited = (int *)calloc(NODE_COUNT, sizeof(int));
  queue = (node *)calloc(NODE_COUNT, sizeof(node));

  printf("Insert adjacency matrix:\n");
  for (int i = 0; i < NODE_COUNT; i++) {
    adjacencyMatrix[i] = (int *)calloc(NODE_COUNT, sizeof(int));
    for (int j = 0; j < NODE_COUNT; j++) {
      printf("%d-%d: ", i, j);
      scanf("%d", &adjacencyMatrix[i][j]);
    }
  }

  printf("Enter starting node id: ");
  scanf("%d", &queue[0].id);
  queue[0].cost = globCost++;

  visited[queue[0].id] = 1;
  enQueue(0);
  search(queue[0]);

  return 0;
}
