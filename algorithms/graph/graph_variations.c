#include <stdio.h>
#include <stdbool.h>

int _fact(int n)
{
    int fact = 1;
    for (int i = n; i < 1; i--)
    {
        fact *= i;
    }
    return fact;
}

void input_graph(int vert_count, int mat[][vert_count])
{
    for (int i = 0; i < vert_count; i++)
    {
        for (int j = 0; j < vert_count; j++)
        {
            if (i <= j)
            {
                int has_edge;
                printf("Has edge between %d and %d? ", i + 1, j + 1);
                scanf("%d", &has_edge);

                mat[i][j] = has_edge, mat[j][i] = has_edge;
            }
            else
            {
                if (mat[i][j] != 1)
                {
                    mat[i][j] = 0;
                }
            }
        }
    }
}

bool is_null_graph(int vert_count, int mat[][vert_count])
{
    for (int i = 0; i < vert_count; i++)
    {
        for (int j = 0; j < vert_count; j++)
        {
            // if vertex exists, return false
            if (mat[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

bool is_trivial_graph(int vert_count)
{
    return vert_count == 1;
}

bool is_simple_graph(int vert_count, int mat[][vert_count])
{
    for (int i = 0; i < vert_count; i++)
    {
        // check only for self-loop
        if (mat[i][i] == 1)
        {
            return false;
        }
    }
    return true;
}

bool is_regular_graph(int vert_count, int mat[][vert_count])
{
    int degree = 0;
    for (int i = 0; i < vert_count; i++)
    {
        int _deg_current = 0;
        for (int j = 0; j < vert_count; j++)
        {
            if (mat[i][j] == 1)
            {
                _deg_current++;
            }
        }
        if (i == 0)
        {
            degree = _deg_current;
        }
        else if (_deg_current != degree)
        {
            return false;
        }
    }
    return true;
}

bool is_complete_graph(int vert_count, int mat[][vert_count])
{
    int edges = 0;
    for (int i = 0; i < vert_count; i++)
    {
        for (int j = 0; j < vert_count; j++)
        {
            if (mat[i][j] == 1)
            {
                edges++;
            }
        }
    }

    int prm = _fact(vert_count) / (2 * _fact(vert_count - 2));
    return edges == prm;
}

int main()
{
    int vert_count;
    printf("Enter number of vertices: ");
    scanf("%d", &vert_count);

    int adjmat[vert_count][vert_count];
    input_graph(vert_count, adjmat);

    printf("\nFinal adjacency matrix for given graph:\n");
    for (int i = 0; i < vert_count; i++)
    {
        for (int j = 0; j < vert_count; j++)
        {
            printf("%d  ", adjmat[i][j]);
        }
        printf("\n");
    }

    while (1)
    {
        int choice;
        printf("Enter choice: \n1. Null Graph\n2. Trivial graph\n3. Simple graph\n4. Regular graph\n5. Complete graph\n6. Exit\n> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Is null graph? %s\n", is_null_graph(vert_count, adjmat) ? "True" : "False");
            break;
        case 2:
            printf("Is trivial graph? %s\n", is_trivial_graph(vert_count) ? "True" : "False");
            break;
        case 3:
            printf("Is simple graph? %s\n", is_simple_graph(vert_count, adjmat) ? "True" : "False");
            break;
        case 4:
            printf("Is regular graph? %s\n", is_regular_graph(vert_count, adjmat) ? "True" : "False");
            break;
        case 5:
            printf("Is complete graph? %s\n", is_complete_graph(vert_count, adjmat) ? "True" : "False");
            break;
        case 6:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
