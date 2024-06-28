#include <stdio.h>

#define INF 9999
#define min(a, b) a < b ? a : b

void input_graph(int vert_count, int mat[][vert_count]) {
    for (int i = 0; i < vert_count; i++) {
        for (int j = 0; j < vert_count; j++) {
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

void show_matrix(int vert_count, int mat[][vert_count]) {
    for (int i = 0; i < vert_count; i++) {
        for (int j = 0; j < vert_count; j++) {
            if (mat[i][j] == INF) {
                printf("∞  ");
            } else {
                printf("%d  ", mat[i][j]);
            }
        }
        printf("\n");
    }
}

void floyd_warshall(int vert_count, int mat[][vert_count]) {
    for (int i = 0; i < vert_count; i++) {
        for (int j = 0; j < vert_count; j++) {
            for (int k = 0; k < vert_count; k++) {
                mat[j][k] = min(mat[j][k], (mat[j][i] + mat[i][k]));
            }
        }
        printf("\n\nR%d:\n", i + 1);
        show_matrix(vert_count, mat);
    }
}

int main() {
    int vert_count;
    printf("Enter number of vertices: ");
    scanf("%d", &vert_count);

    int mat[vert_count][vert_count];
    input_graph(vert_count, mat);

    printf("\nmatrix for given graph:\n");
    show_matrix(vert_count, mat);

    floyd_warshall(vert_count, mat);
    printf("This is the all pairs shortest path matrix\n");
    return 0;
}
