#include <stdio.h>
#include <stdlib.h>

struct edge {
    int from, to, w;
} e;

void input_graph(int vcount, int mat[][vcount]) {
    for (int i = 0; i < vcount; i++) {
        for (int j = 0; j < vcount; j++) {
            int w;
            printf("Edge weight of (%d, %d)? ", i + 1, j + 1);
            scanf("%d", &w);
            mat[i][j] = w;
        }
    }
}

void kruskal(int vcount, int mat[][vcount]) {
    // sort edges
    int edge[vcount * vcount];
}

int main() {
    int vcount;
    printf("Enter number of vertices: ");
    scanf("%d", &vcount);

    int mat[vcount][vcount];
    input_graph(vcount, mat);

    printf("\n");
    return 0;
}
