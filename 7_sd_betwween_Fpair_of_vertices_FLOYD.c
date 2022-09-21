/* 7.	For a weighted directed Graph, find shortest distances between every pair of vertices. (Floyds) */

#include<stdio.h>
int min(int a,int b){
return (a<b) ? a : b;
}
int main(){
int i,j,k,n;
int a[10][10];
printf("Enter the no of vertices\n");
scanf("%d",&n);
printf("Enter the adjacency matrix\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}
for(k=0;k<n;k++){
for(i=0;i<n;i++){
for(j=0;j<n;j++){
a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
}
}
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d ",a[i][j]);
}
printf("\n");
}

}
