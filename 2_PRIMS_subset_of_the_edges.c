/* 2.	Given a weighted undirected graph. Finds a subset of the edges that forms a tree that includes every
vertex, where the total weight of all the edges in the tree is minimized by using prims approach. */

prims

#include <stdio.h>

int prims(int cost[10][10],int n,int t[10][10])

{

int min=9999,k,l,near[10],j,mincost=0,i,index;

for(i=1;i<=n;i++)

{

for(j=i+1;j<=n;j++)

{

if(cost[i][j]<min&&cost[i][j]!=0)

{

min=cost[i][j];

k=i;

l=j;

}

}

}

t[1][1]=k;

t[1][2]=l;

mincost=mincost+cost[k][l];

for(i=1;i<=n;i++)

{

if(cost[i][l]<cost[i][k])

near[i]=l;

else

near[i]=k;

}

near[k]=0;

near[l]=0;

for(i=2;i<=n-1;i++)

{

min=9999;

for(j=1;j<=n;j++)

{

if(near[j]!=0&&cost[j][near[j]]<min){

   min=cost[j][near[j]];

   index=j;

}

}

t[i][1]=index;

t[i][2]=near[index];

mincost=mincost+cost[index][near[index]];

   near[index]=0;

for(k=1;k<=n;k++)

{

if(near[k]!=0&&cost[k][near[k]]>cost[k][index])

near[k]=index;

}

}

return mincost;

}

int main()

{

    int n,t[10][10],mincost=0;

    printf("Enter n value:");

    scanf("%d",&n);

    printf("Enter cost matrix\n");

int i,j,c[10][10];

for(i=1;i<=n;i++)

for(j=1;j<=n;j++)

scanf("%d",&c[i][j]);

mincost=prims(c,n,t);

printf("Minimum cost=%d\n",mincost);

return 0;

}
