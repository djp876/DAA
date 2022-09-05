#include<stdio.h>
struct edge{
    int u,v,cost;
};
int main(){
    int i,n,j,mincost=0,big_num=999,k;
    int parent[10];
    int cost[10][10];
    int t[10][2];
    struct edge edges[10];
    struct edge e;
    int c=0;
    printf("Enter the no of edges: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(i<j && cost[i][j] != big_num){
                e.u=i;
                e.v=j;
                e.cost = cost[i][j];
                edges[c++]=e;
            }
        }
    }
    
    for(i=0;i<c;i++){
        for(j=i+1;j<c;j++){
            if(edges[j].cost < edges[i].cost){
                e = edges[i];
                edges[i]=edges[j];
                edges[j]=e;
            }
        }
    }
    for(i=0;i<n;i++){
        parent[i]=-1;
    }
    i=0;
    int tc=0;
    while(i<c){
        e = edges[i];
        j = e.u;
        k = e.v;
        while(parent[j] != -1){
            j = parent[j];
        }
        while(parent[k] != -1){
            k = parent[k];
        }
        if(j != k){
            mincost+=e.cost;
            if(parent[e.u] != -1) parent[e.v]=e.u;
            else parent[e.u] = e.v;
            t[tc][0]=e.u;
            t[tc][1]=e.v;
            tc++;
        }
        i++;
    }
    printf("minimum cost is %d\n",mincost);
    printf("Spanning tree is :\n");
    for(i=0;i<tc;i++){
        for(j=0;j<2;j++) printf("%d ",t[i][j]+1);
        printf("\n");
    }
}
