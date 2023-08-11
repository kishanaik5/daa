#include<stdio.h>
#include<stdlib.h>

int n1, v[10], visited[10], cost[10][10], n, i, j, s, k = 0, l = 0, min_tree[10], order[10];

void prims(int s);

void main()
{
    printf("enter the number of nodes : \n");
    scanf("%d", &n);

    printf("enter the cost matrix enter the cost if exists else 0 : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("enter the start node : ");
    scanf("%d", &s);
    prims(s);
}

void prims(int s)
{
    n1 = n - 1;
    order[k++] = s;
    visited[s] = 1;

    while (n1 > 0)
    {
        int min = 99999;
        int min_vertex;

        for (i = 0; i < k; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[order[i]][j] != 0 && visited[j] == 0)
                {
                    if (cost[order[i]][j] < min)
                    {
                        min = cost[order[i]][j];
                        min_vertex = j;
                    }
                }
            }
        }

        order[k++] = min_vertex;
        visited[min_vertex] = 1;
        min_tree[l++] = min;
        n1--;
    }

    printf("Minimum Spanning Tree edges:\n");
    for(i=0;i<n-1;i++)
    {
        printf("%d\t",min_tree[i]);
    }
}
