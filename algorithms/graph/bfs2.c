#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) return -1;
    item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void bfs(int mat[][MAX], int startVertex, int V) {
    Queue* q = createQueue();
    int visited[MAX] = {0};

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < V; i++) {
            if (mat[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    free(q);
}

int main() {
    int V, edges, src, dest, startVertex;
    printf("Number of vertices: ");
    scanf("%d", &V);

    int mat[MAX][MAX] = {0}; // initialize all edge weights with 0

    printf("Number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (from,to): ");
        scanf("%d,%d", &src, &dest);
        mat[src][dest] = 1;
        mat[dest][src] = 1;
    }

    printf("Starting vertex: ");
    scanf("%d", &startVertex);

    printf("\nBFS traversal starting from vertex %d:\n", startVertex);
    bfs(mat, startVertex, V);
    printf("\n");
    return 0;
}
