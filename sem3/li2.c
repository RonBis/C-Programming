#include <stdio.h>
int main()
{
    int n, i, j, x[10], y[10], a[i][j], xin, wi = 1, di;
    float yidi, sum_yidi = 0.0, lx = 1.0;
    printf("Enter the number of input: ");
    scanf("%d", &n);
    printf("Enter the value of 'x' :", x);
    scanf("%d", &xin);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the value of x%d: ", i);
        scanf("%d", &x[i]);
        printf("\nEnter the value of y%d:", i);
        scanf("%d", &y[i]);
    }
    for (i = 0; i < n; i++)
        printf("x%d=%d\t", i, x[i]);
    printf("\n");

    for (i = 0; i < n; i++)
        printf("y%d=%d\t", i, y[i]);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                a[i][j] = xin - x[i];
                wi = wi * a[i][j]; // product of diagonal
            }
            else
                a[i][j] = x[i] - x[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("Di\tyi\tyi/Di\n");
    for (i = 0; i < n; i++)
    {
        di = 1;
        for (j = 0; j < n; j++)
        {
            di = di * a[i][j]; // product of row
        }
        yidi = ((float)y[i] / di); // f(x)/product of row
        sum_yidi = sum_yidi + yidi;
        printf("%d\t%d\t%.4f\n", di, y[i], yidi);
    }
    lx = (float)(wi)*sum_yidi;
    printf("\nThe Lagrange interpolation is:%.4f\n", lx);
}