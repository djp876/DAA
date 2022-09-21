/* 9.	Given a Set, find subset of elements that are selected from the set whose sum adds up to a given
number K. We are considering the set contains nonnegative values. It is assumed that the input set is
unique (no duplicates are presented) (Sum of subsets problem) */

#include<stdio.h>
int x[10],m,w[10],n;
int sumofsubsets(int s,int k,int r)
{
int i;
x[k]=1;
if(s+w[k]==m){
for(i=1;i<=k;i++)
printf("%d\t",x[i]);
}
else if(s+w[k]+w[k+1]<=m)
sumofsubsets(s+w[k],k+1,r-w[k]);
if((s+r-w[k]>=m) && (s+w[k+1]<=m))
{
x[k]=0;
sumofsubsets(s,k+1,r-w[k]);
}
}
int main()
{
int k=1,s=0,r=0,i;
printf("Enter no.of instances:");
scanf("%d",&n);
printf("Enter knapsack capacity:");
scanf("%d",&m);
printf("Enter weights:\n");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);
for(i=1;i<=n;i++)
r=r+w[i];
for(i=1;i<=n;i++)
x[i]=0;
sumofsubsets(s,k,r);
}
