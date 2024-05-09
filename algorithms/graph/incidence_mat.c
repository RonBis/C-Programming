#include <stdio.h>

void input_graph(int v, int e, int mat[v][e])
{
    printf("Input graph:\nChoose\na) 1 for outgoing edge\nb) -1 for incoming edge\nc) 0 for no edge\n\n");
    // iterate over edges
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        printf("Edge e%c: ", i + 1);
        scanf("%d, %d", &src, &dest);

        src -= 1;
        dest -= 1;

        mat[src][i] = 1;
        mat[dest][i] = -1;
    }
}

int main()
{
    int v, e;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    int adjmat[v][e];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            adjmat[i][j] = 0;
        }
    }

    input_graph(v, e, adjmat);

    printf("\nFinal incidence matrix for given graph:\n");

    //print edge names
    printf("  \t");
    for (int i = 0; i < e; i++)
    {
        printf("e%d  ", i + 1);
    }
    printf("\n");

    // print incidence matrix
    for (int i = 0; i < v; i++)
    {
        printf("v%d:\t", i + 1);
        for (int j = 0; j < v; j++)
        {
            printf("%d   ", adjmat[i][j]);
        }
        printf("\n");
    }
    return 0;
}