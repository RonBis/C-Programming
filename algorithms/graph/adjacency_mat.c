#include <stdbool.h>
#include <stdio.h>

void input_graph(int vert_count, int mat[][vert_count]) {
    for (int i = 0; i < vert_count; i++) {
        for (int j = 0; j < vert_count; j++) {
            if (i <= j) {
                int has_edge;
                printf("Has edge between %d and %d? ", i + 1, j + 1);
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
    int vert_count;
    printf("Enter number of vertices: ");
    scanf("%d", &vert_count);

    int adjmat[vert_count][vert_count];
    input_graph(vert_count, adjmat);

    printf("\nFinal adjacency matrix for given graph:\n");
    for (int i = 0; i < vert_count; i++) {
        for (int j = 0; j < vert_count; j++) {
            printf("%d  ", adjmat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
