/* 11.The N-Queen’s puzzle is the problem of placing N chess queens on an N×N chessboard so that no
two queens threaten each other. Thus, a solution requires that no two queens share the same row, column,
or diagonal. Provide a solution by using Backtracking*/
NQueens

#include<stdio.h>

#include<stdlib.h>

#include<math.h>

int place(int,int,int);

int x[10];

int nqueens(int k,int n)

{

int i;

for(i=1;i<=n;i++)

{

if(place(k,i,n))

{

x[k]=i;

if(k==n){

for(i=1;i<=n;i++)

printf("%d\t",x[i]);

printf("\n");

}

else

nqueens(k+1,n);

}

}

}

int place(int k,int i,int n)

{

int j;

for(j=1;j<=k-1;j++){

if((x[j]==i)|| (abs(x[j]-i)==abs(j-k)))

return 0;

}

return 1;

}

int main()

{

int n,count=0,i;

printf("Enter no.of queens:");

scanf("%d",&n);

for(i=1;i<=n;i++)

x[i]=0;

nqueens(1,n);

return 0;

}
