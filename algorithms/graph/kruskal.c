#include <stdio.h>
#include <stdlib.h>

void sortEdges(int E, int edges[E][3]) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j][2] > edges[j+1][2]) {
                
                int temp_src = edges[j][0];
                int temp_dest = edges[j][1];
                int temp_weight = edges[j][2];
                
                edges[j][0] = edges[j+1][0];
                edges[j][1] = edges[j+1][1];
                edges[j][2] = edges[j+1][2];
                
                edges[j+1][0] = temp_src;
                edges[j+1][1] = temp_dest;
                edges[j+1][2] = temp_weight;
            }
        }
    }
}

int find(int parent[], int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void unionSets(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

void kruskal(int V, int E, int edges[E][3]) {
    int result[V-1][3], ne = 0, e = 0, parent[V], i;
    
    sortEdges(E, edges);
    
    for (i = 0; i < 5; i++)
        parent[i] = i;
    
    while (ne < V - 1) {
        int u = edges[e][0];
        int v = edges[e][1];
        int w = edges[e][2];
        e++;
        
        int x = find(parent, u);
        int y = find(parent, v);
        if (x != y) {
            result[ne][0] = u;
            result[ne][1] = v;
            result[ne][2] = w;
            ne++;
            unionSets(parent, x, y);
        }
    }
    
    printf("\n-- Kruskal's MST Edges --\n");
    int minimumCost = 0;
    for ( i = 0; i < ne; i++) {
        printf("%d - %d == %d\n", result[i][0], result[i][1], result[i][2]);
        minimumCost += result[i][2];
    }
    printf("Minimum spanning tree cost: %d\n", minimumCost);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    int edges[E][3];
    printf("Input as (from to cost) (separated by space)\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }
    kruskal(V, E, edges);
    return 0;
}
