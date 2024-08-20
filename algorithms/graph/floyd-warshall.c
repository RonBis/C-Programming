#include <stdio.h>

#define INF 9999
#define min(a, b) a < b ? a : b

void input_graph(int V, int mat[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                mat[i][j] = 0;
                continue;
            }
            int weight;
            printf("Weight of edge from %d to %d? ", i + 1, j + 1);
            scanf("%d", &weight);
            mat[i][j] = (weight == 0) ? INF : weight;
        }
    }
}

void show_matrix(int V, int mat[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (mat[i][j] == INF) {
                printf("∞  ");
            } else {
                printf("%d  ", mat[i][j]);
            }
        }
        printf("\n");
    }
}

void floyd(int V, int mat[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; k < V; k++) {
                mat[j][k] = min(mat[j][k], (mat[j][i] + mat[i][k]));
            }
        }
        // printf("\n\nR%d:\n", i + 1);
        // show_matrix(V, mat);
    }
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int mat[V][V];
    input_graph(V, mat);

    printf("\nCost matrix for given graph:\n");
    show_matrix(V, mat);

    printf("\nAll pairs shortest path matrix:\n");
    floyd(V, mat);
    show_matrix(V, mat);
    return 0;
}
