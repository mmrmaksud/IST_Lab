//8. Write a program to implement dynamic programming method for all pair's shortest path problem.

#include <stdio.h>
#include <stdlib.h>
#define INF 9999
void allPairsShortestPath(int w[10][10], int n)
{
    int q[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q[i][j] = w[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (q[i][k] + q[k][j] < q[i][j])
                {
                    q[i][j] = q[i][k] + q[k][j];
                }
            }
        }
        printf("\nMatrix %d is: \n", k + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("\t%d ", q[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int w[10][10];
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    printf("Enter the values of the matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &w[i][j]);
            if (w[i][j] == 0 && i != j)
            {
                w[i][j] = INF;
            }
        }
    }
    allPairsShortestPath(w, n);

    return 0;
}
