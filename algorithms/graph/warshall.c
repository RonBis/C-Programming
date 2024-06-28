#include <stdio.h>

void input_graph(int vert_count, int mat[][vert_count]) {
    for (int i = 0; i < vert_count; i++) {
        for (int j = 0; j < vert_count; j++) {
            if (i == j) {
                mat[i][j] = 0;
                continue;
            }
            printf("Has edge between %d from %d? (1/0) ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void show_matrix(int vert_count, int mat[][vert_count]) {
    for (int i = 0; i < vert_count; i++) {
        for (int j = 0; j < vert_count; j++) {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}

void floyd_warshall(int vert_count, int mat[][vert_count]) {
    for (int i = 0; i < vert_count; i++) {
        for (int j = 0; j < vert_count; j++) {
            for (int k = 0; k < vert_count; k++) {
                mat[j][k] = mat[j][k] || (mat[j][i] && mat[i][k]);
            }
        }
        printf("\n\nR%d:\n", i+1);
        show_matrix(vert_count, mat);
    }
}

int main() {
    int vert_count;
    printf("Enter number of vertices: ");
    scanf("%d", &vert_count);

    int mat[vert_count][vert_count];
    input_graph(vert_count, mat);

    printf("\nFinal adjacency matrix for given graph:\n");
    show_matrix(vert_count, mat);

    floyd_warshall(vert_count, mat);

    return 0;
}
