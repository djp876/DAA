/* 4.	Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the
given graph. (Dijkstras) */

#include<stdio.h>
void dijkstra(int v,int c[10][10],int d[10],int n)
{
int s[10],p,min,i,w,u;
for(i=1;i<=n;i++)
{
s[i]=0;
d[i]=c[v][i];
}
d[v]=0;
s[v]=1;
for(min=2;min<=n-1;min++)
{
for(i=1;i<=n;i++)
{
if(s[i]!=1)
{
min=d[i];
u=i;
break;
}
   }
for(i=1;i<=n;i++)
{
   if(d[i]!=0)
  {
   if(d[i]<min&&s[i]!=1)
  {
  min=d[i];
  u=i;
   }
}
}
s[u]=1;
for(w=1;w<=n;w++){
    s[u]=1;
}
for(w=1;w<=n;w++)
{
   if(c[u][w]!=0&&c[u][w]!=9999&&s[w]==0)
{
    if(d[w]>d[u]+c[u][w]){
   d[w]=d[u]+c[u][w];
    }
}
}
}
for(i=1;i<=n;i++)
 printf("\n Distance from source %d to vertex %d: %d", v,i,d[i]);
}
int main()
{
int n,i,j,v;
int d[10],c[10][10];
printf("Enter no.of vertices:");
scanf("%d", &n);
printf("Enter adjacency matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d", &c[i][j]);
}
}
printf("Enter the source vertex:");
scanf("%d", &v);
dijkstra(v,c,d,n);
printf("\n");
return 0;
}
