#include <stdio.h>
#include <stdlib.h>

int cost[10][10], d[10], i, j, n, s, visited[10], order[10], k = -1;

void dij(int s);

void main() {
    printf("enter the number of nodes : \n");
    scanf("%d", &n);

    printf("enter the cost of path if path exists else enter 0 : \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        d[i] = 10000;
        visited[i] = 0;
    }

    printf("enter the start node : \n");
    scanf("%d", &s);

    d[s] = 0;
    order[++k] = s;
    dij(s);

    for (i = 0; i <= n; i++) {
        printf("%d\t", d[i]);
        
    }
    
}

void dij(int s) {
    visited[s] = 1;

    for (i = 0; i < n; i++) {
        if (cost[s][i] != 0 && d[i] > d[s] + cost[s][i]) {
            d[i] = d[s] + cost[s][i];
        }
    }

    int min = -1;
    for (i = 0; i < n; i++) {
        if (!visited[i] && (min == -1 || d[i] < d[min])) {
            min = i;
        }
    }

    if (min != -1) {
        order[++k] = min;
        dij(min);
    }
}
