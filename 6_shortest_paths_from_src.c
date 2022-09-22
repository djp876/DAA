/* 6. Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the 

 given graph. The graph may contain negative weight edges. (Bellmen ford) */


#include<stdio.h>

int n,cost[10][10],dist[10],v;

int bellmanford(int v,int cost[10][10],int n)

{

int i,u,k;

for(i=1;i<=n;i++)

dist[i]=cost[v][i];

for(k=2;k<=n-1;k++)

{

for(u=2;u<=n;u++)

{

for(i=2;i<=n;i++)

{

if(dist[u]>dist[i]+cost[i][u])

dist[u]=dist[i]+cost[i][u];

}

}

printf("%d",dist[k]);

}

printf("The shortest distances are: ");

for(i=1;i<=n;i++)

printf("%d\t",dist[i]);

}

int main()

{

int i,j;

printf("Enter no.of vertices:");

scanf("%d",&n);

printf("Enter cost matrix\n");

for(i=1;i<=n;i++)

for(j=1;j<=n;j++)

scanf("%d",&cost[i][j]);

printf("Enter source vertex:");

scanf("%d",&v);

bellmanford(v,cost,n);

}

/*

0 6 5 5 999 999 999

999 0 999 999 -1 999 999

999 -2 0 999 1 999 999

999 999 -2 0 999 -1 999

999 999 999 999 0 999 3

999 999 999 999 999 0 3

999 999 999 999 999 999 0

*/
