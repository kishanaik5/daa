#include<stdio.h>
#include<stdlib.h>

int w[10],s[10],f[10],m[10],p[10],i,j,n,c,k=1;
void find(int i);
int max(int a,int b)
{
    return (a>b)? a:b;
}
void main()
{
    printf("enter the number of requests : \n");
    scanf("%d",&n);
    
    printf("enter the start , finish and profit : \n");
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&s[i],&f[i],&w[i]);
    }
    p[k++]=0;
    for(i=2;i<=n;i++)
    {
        c=0;
        for(j=1;j<i;j++)
        {
            if(s[i]>=f[j])
            {
                c++;
            }
        }
        p[k++]=c;
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\t",p[i]);
    }
    printf("\n");
    
    
    m[0]=0;
    for(i=1;i<=n;i++)
    {
        m[i]=max(w[i]+m[p[i]],m[i-1]);
    }
    
    for(i=0;i<=n;i++)
    {
        printf("%d\t",m[i]);
    }
    printf("\n");
    printf("the intervals with max weight is : \n");
    find(i);
    
}


void find(int i)
{
    if(i>0)
    {
        if(w[i]+m[p[i]]>m[i-1])
        {
            printf("%d - %d : %d\n",s[i],f[i],w[i]);
            find(p[i]);
        }
        else
        {
            find(i-1);
        }
    }
}
