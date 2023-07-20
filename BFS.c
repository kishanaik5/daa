#include<stdio.h>
#include<stdlib.h>

int graph[10][10],visited[10],n,i,j,s,q[10],f=0,r=-1;
void bfs(int v);
void main()
{
    printf("enter the number of vertices : \n");
    scanf("%d",&n);
    printf("enter the adjacency matrix  : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }

    printf("enter the start vertex : \n");
    scanf("%d",&s);
    
    bfs(s);
    
    printf("the reachable nodes are : \n ");
    for(i=0;i<n;i++)
    {
        if(visited[i]==1)
        {
            printf("%d\t",i);
        }
    }
}

void bfs(int v)
{
    for(i=0;i<n;i++)
    {
        if(graph[v][i]==1 && visited[i]==0)
        {
            q[++r]=i;
        }
    }
    
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[++f]);
    }
}
