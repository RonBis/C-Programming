#include <stdio.h>
#include <stdlib.h>

#define INF 9999

typedef struct Edge {
    int from, to, weight;
} Edge;

int *visited;

void input_graph(int V, int mat[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i < j) {
                int weight;
                printf("Weight of edge from %d to %d? ", i + 1, j + 1);
                scanf("%d", &weight);
                weight = (weight == 0) ? INF : weight;
                mat[i][j] = weight, mat[j][i] = weight;
            } else if(i == j) {
                mat[i][j] = INF;
            } else if(mat[j][i] != INF) {
                mat[i][j] = mat[j][i];
            }
        }
    }
}

Edge findMinCostConn(int from, int V, int mat[][V]) {
    int mincost = INF, mincostVertexId;
    // iterate over each edges
    for (int i = 0; i < V; i++) {
        // if vertex is visited, skip iteration
        if (visited[V] == 1) continue;

        int currentEdgeCost = mat[from][V];
        if (currentEdgeCost < mincost) {
            mincost = currentEdgeCost;
            mincostVertexId = V;
        }
    }
    return (Edge){.from = from, .to = mincostVertexId, .weight = mincost};
}

int main() {
    int V, startVertex, cost = 0;
    printf("Number of vertices: ");
    scanf("%d", &V);
    int mat[V][V];
    visited = (int *)calloc(V, sizeof(int));

    input_graph(V, mat);
    printf("Starting vertex: ");
    scanf("%d", &startVertex);

    visited[startVertex] = 1;  // mark startVertex as visited
    int src = startVertex;
    for (int i = 0; i < V; i++) {
        Edge e = findMinCostConn(src, V, mat);
        printf("from:%d to:%d cost:%d\n", e.from, e.to, e.weight);
        src = e.to;
    }
    return 0;
}
