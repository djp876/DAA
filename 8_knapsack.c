/* 8.	Given weights and values of n items, we need to put these items in a knapsack of capacity W to get */

#include<stdio.h>
float knapsack(float p[10],float w[10],float x[10],float n,float m)
{
float cu=m,sum=0;
int i;
for(i=1;i<=n;i++)
{
if(w[i]>cu)
break;
else
{
x[i]=1;
cu=cu-w[i];
}
}
for(i=1;i<=n;i++)
{
sum=sum+(p[i]*x[i]);
}
return sum;
}
int main()
{
float n,m,p[10],w[10],x[10],a=0,result;
int i,j;
printf("Enter no.of elements to be inserted:");
scanf("%f",&n);
printf("Capacity of knapsack:");
scanf("%f",&m);
printf("Enter profits Pi\n");
for(i=1;i<=n;i++)
scanf("%f",&p[i]);
printf("Enter weights Wi\n");
for(i=1;i<=n;i++)
scanf("%f",&w[i]);
for(i=1;i<=n;i++)
x[i]=p[i]/w[i];
    for (i = 1; i <= n; ++i){
  for (j = i +1 ; j <= n; ++j){
    if (x[i] < x[j])
  {
  a = x[i];
  x[i] = x[j];
  x[j] = a;
  }
  }
    }
    result=knapsack(p,w,x,n,m);
    printf("The maximised profit is: %.2f\n",result);
}
