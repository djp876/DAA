/* 10.	Given a Graph, determine whether a given graph contains Hamiltonian Cycle or not. */

#include<stdio.h>
int G[10][10],x[10],n;
void nextvalue(int);
void hamilton(int k)
{
int i;
do
{
nextvalue(k);
if(x[k]==0)
return;
if(k==n){
for(i=1;i<=n;i++)
printf("%d\t ",x[i]);
printf("\n");
}
else
hamilton(k+1);
}while(1);
}
void nextvalue(int k)
{
int j,s;
   do
   {
    x[k]=(x[k]+1)%(n+1);
    if(x[k]==0)
    return;
    if(G[x[k-1]][x[k]]!=0)
    {
    for(j=1;j<=k-1;j++)
    {
  if(x[j]==x[k])
  break;
  }
    if(j==k)
    if((k<n) || ((k==n) && G[x[n]][x[1]]!=0))
    return;
    }
   }while(1);
}
int main()
{
int i,j;
printf("Enter no.of vertices:");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d", &G[i][j]);
x[1]=1;
for(i=2;i<=n;i++){
x[i]=0;
}
hamilton(2);
}
