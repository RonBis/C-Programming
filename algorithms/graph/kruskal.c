#include <stdio.h>
#include <stdlib.h>

void input_graph(int v, int mat[][v]) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j) {
                mat[i][j] = 0;
            } else if (i < j) {
                int weight;
                printf("Edge weight (%d--%d)? ", i + 1, j + 1);
                scanf("%d", &weight);
                mat[i][j] = weight, mat[j][i] = weight;
            }
        }
    }
}

void show_matrix(int v, int G[][v]) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d  ", G[i][j]);
        }
        printf("\n");
    }
}

typedef struct _2DIndex_ {
    int i, j;
} _2DIndex_;

_2DIndex_ get_2d_index(int v, int size) {
    return (_2DIndex_){.i = v / size, .j = v % size};
}

typedef struct Edge {
    int a, b, weight;
} Edge;

void sort_edges(int v, int G[][v], Edge *sorted_edges) {
    int size = v * v;
    int sorted_edges_count = 0;

    for (int step = 0; step < size; step++) {
        if (*(*G + step) == 0) continue;

        int min = *(*G + step), minpos = step;
        for (int i = step + 1; i < size; i++) {
            if (*(*G + i) == 0) continue;
            if (*(*G + i) < min) {
                // swap G[step] and G[i] values
                min = *(*G + i);
                minpos = i;
                *(*G + i) = *(*G + step);
            }
        }

        _2DIndex_ idx = get_2d_index(minpos, v);
        sorted_edges[sorted_edges_count++] = (Edge){
            .a = idx.i,
            .b = idx.j,
            .weight = min,
        };
    }

    for (int i = 0; i < v * v; i++) {
        printf("%d--%d > %d\n", sorted_edges[i].a, sorted_edges[i].b, sorted_edges[i].weight);
    }
}

void kruskal(int v, int G[][v]) {
    Edge edge[v];
    sort_edges(v, G, edge);
    for (int i = 0; i < v * v; i++) {
        printf("%d--%d > %d\n", edge[i].a, edge[i].b, edge[i].weight);
    }
}

int main() {
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    int G[v][v];
    input_graph(v, G);
    show_matrix(v, G);
    kruskal(v, G);

    printf("\n");
    return 0;
}
