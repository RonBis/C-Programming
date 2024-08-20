#include <stdio.h>

void input_graph(int V, int mat[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                mat[i][j] = 0;
                continue;
            }
            printf("Has edge from %d to %d? (1/0) ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void show_matrix(int V, int mat[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}

void warshall(int V, int mat[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; k < V; k++) {
                mat[j][k] = mat[j][k] || (mat[j][i] && mat[i][k]);
            }
        }
        // printf("\n\nR%d:\n", i+1);
        // show_matrix(V, mat);
    }
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    int mat[V][V];
    input_graph(V, mat);
    printf("\nAdjacency matrix for given graph:\n");
    show_matrix(V, mat);
    warshall(V, mat);
    printf("\nTransitive closure for given graph:\n");
    show_matrix(V, mat);
    return 0;
}
