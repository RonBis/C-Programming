#include <stdio.h>
#include <stdlib.h>

void input_graph(int vert_count, int mat[][vert_count]) {
    for (int i = 0; i < vert_count; i++) {
        for (int j = 0; j < vert_count; j++) {
            if(i == j) {
                mat[i][j] = 0;
            }
            else if (i < j) {
                int has_edge;
                printf("Has edge between %d and %d? ", i, j);
                scanf("%d", &has_edge);

                mat[i][j] = has_edge, mat[j][i] = has_edge;
            }
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

void dfs(int start, int v, int G[][v]) {
    int stack[v], visited[v];
    int top = -1;
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }

    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) {
        int currentVertex = stack[top--];
        printf("%d\t", currentVertex);

        for (int i = v - 1; i >= 0; i--) {
            if (G[currentVertex][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    int mat[v][v];
    int visited[v];
    input_graph(v, mat);

    printf("\nInput graph:\n");
    show_matrix(v, mat);

    int start;
    printf("\nEnter dfs start vertex: ");
    scanf("%d", &start);

    // 0 elements in visited array
    dfs(start, v, mat);
    printf("\n");
    return 0;
}
