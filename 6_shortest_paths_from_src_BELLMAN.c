/* 6.	Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the
given graph. The graph may contain negative weight edges. (Bellmen ford) */

#include<stdio.h>
int min(int a,int b){
return (a<b) ? a : b;
}
int main(){
int i,j,k,s,n,l;
int cost[10][10];
int dist[10]={0};
int temp[10]={0};
printf("Enter the no of vertices\n");
scanf("%d",&n);
printf("Enter the source vertex\n");
scanf("%d",&s);
printf("Enter the adjacency matrix\n");
for(i=1;i<=n;i++){
for(j=1;j<=n;j++) scanf("%d",&cost[i][j]);
}
for(i=1;i<=n;i++){
dist[i] = cost[s][i];
}
for(k=2;k<=n;k++){
for(l=1;l<=n;l++) temp[l] = dist[l];
for(j=1;j<=n;j++){
int mn = 99;
for(i=1;i<=n;i++){
if(i != s){
mn = min(mn,temp[i]+cost[i][j]);
}
}
dist[j] = min(dist[j],mn);
}
}
printf("shortest path from source vertex to all vertices\n");
for(i=1;i<=n;i++) printf("%d ",dist[i]);
printf("\n");
}
