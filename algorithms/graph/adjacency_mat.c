#include <stdio.h>

void input_graph(int V, int mat[][V]) {
    printf("-- Input graph --\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i <= j) {
                int has_edge;
                printf("Has edge between %d and %d? (0 means no, 1 means yes) ", i + 1, j + 1);
                scanf("%d", &has_edge);
                mat[i][j] = has_edge, mat[j][i] = has_edge;
            } else {
                if (mat[i][j] != 1) {
                    mat[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int adjmat[V][V];
    input_graph(V, adjmat);

    printf("\nAdjacency matrix for given graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d  ", adjmat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
