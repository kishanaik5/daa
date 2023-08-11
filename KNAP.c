#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int w[10],p[10],i,j,cap,n;



void main()
{
    printf("enter the capacity : \n");
    scanf("%d",&cap);
    printf("enter the number of objects : \n");
    scanf("%d",&n);
    int l[n+1][cap+1];
    bool selected[n+1][cap+1];
    printf("enter the weights and its profits (increasing order of weight) :\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&p[i]);
    }
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cap;j++)
        {
            if(i==0||j==0)
            {
                l[i][j]=0;
                selected[i][j]=false;
            }
            else if (w[i]<=j)
            {
                if(p[i]+l[i-1][j-w[i]]>l[i-1][j])
                {
                    l[i][j]=p[i]+l[i-1][j-w[i]];
                    selected[i][j]=true;
                }
                else
                {
                    l[i][j]=l[i-1][j];
                    selected[i][j]=false;
                }
            }
            else
            {
                l[i][j]=l[i-1][j];
                selected[i][j]=false;
            }
        }
    }
    i=n;
    j=cap;
    printf("the objects are : \n");
    while(i>0 && j>0)
    {
        if(selected[i][j])
        {
            printf("the selected weight is : %d and its profit is : %d \n",w[i],p[i]);
            j=j-w[i];
        }
        i--;
    }
    printf("the max profit is : %d \n",l[n][cap]);
}
