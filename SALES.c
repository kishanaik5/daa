#include <stdio.h>
#include <stdlib.h>

int visited[10], n, s, i, j, cost[10][10], c = 0, n1;
void trav(int s);

void main() {
    printf("enter the number of nodes : \n");
    scanf("%d", &n);

    printf("enter the cost matrix : \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("enter the start node : \n");
    scanf("%d", &s);
    trav(s);
    printf("the cost is : %d", c);
}

void trav(int s) {
    visited[s] = 1;
    int min_cost = 9999;
    int nearest_neighbor = -1;
    for (i = 0; i < n; i++) 
    {
        if (cost[s][i] != 0 && cost[s][i] < min_cost && visited[i] == 0) 
        {
            min_cost = cost[s][i];
            nearest_neighbor = i;
        }
    }

    if (nearest_neighbor == -1) {
        c += cost[s][0];  
        return;
    }

    c += min_cost;
    trav(nearest_neighbor); 
}
