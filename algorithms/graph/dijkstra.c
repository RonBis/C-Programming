#include <stdio.h>
#include <stdlib.h>

#define INF 9999

int minDistance(int V, int dist[V], int visited[V]) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int V, int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF, visited[i] = 0;
    }

    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(V, dist, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int graph[V][V];
    for (i = 0; i < V; i++) {  // initialize matrix
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < E; i++) {
        int u, v, w;
        printf("Edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        if (u >= 0 && u < V && v >= 0 && v < V) {
            graph[u][v] = w;
            graph[v][u] = w;  // For undirected graph
        } else {
            printf("Invalid vertex.\n");
            i--;
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    int src;
    printf("\nEnter the source vertex: ");
    scanf("%d", &src);
    printf("\nDijkstra's Shortest Path:\n");
    dijkstra(V, graph, src);
    return 0;
}