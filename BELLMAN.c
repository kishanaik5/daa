#include<stdio.h>
#include<stdlib.h>

int distance[10],cost[10][10],i,j,k=1,n,s,visited[10];

void bellman(int s){
    for(k=1;k<=n-1;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(cost[i][j] != 0 && distance[i] + cost[i][j] < distance[j]){
                    distance[j] = cost[i][j] + distance[i];
                }
            }
        }
    }
}

void main(){
    int c = 0;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    
    printf("please enter the cost matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",cost[i][j]);
        }
        
    }
    for(i=0;i<n;i++){
        distance[i]= 10000;
        visited[i] = 0;
    }
    
    printf("enter the start node:");
    scanf("%d",&s);
    distance[s]=0;
    bellman(s);
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (cost[i][j] != 0 && distance[i] + cost[i][j] < distance[j]){
                c=1;
            }
        }
    }
    if(c==1){
        printf("negatice cycle exist!\n");
    }
    else{
        for(i=0;i<n;i++){
            printf("%d\t",distance[i]);
        }
    }
}
