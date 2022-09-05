#include<stdio.h>
int main()
{
struct p 
{
int pid;
int bt;
int cbt;
int wt;
int tat;
} a[10];
int tq,n,i,pt=0,max=0;
float awt;
printf("enter no of processes\n");
scanf("%d",&n);
printf("Enter time Quantam\n");
scanf("%d",&tq);
for(i=0;i<n;i++)
{
printf("enter processid ,Burst Time \n");
scanf("%d%d",&a[i].pid,&a[i].bt);
a[i].cbt=a[i].bt;
max+=a[i].bt;
}
/*for(i=0;i<n;i++)
printf("%d\t",a[i].cbt);
printf("max=%d",max);*/
while(pt!=max)
{
for(i=0;i<n;i++)
{
if(a[i].cbt<tq&&a[i].cbt!=0)
{
pt+=a[i].cbt;
a[i].wt=pt-a[i].cbt;
a[i].tat=pt;
a[i].cbt=0;
}
else
{
pt+=tq;
a[i].cbt-=tq;
}
}
}
printf("Process ID\tBurst Time\tWaiting Time\tTurn Around Time\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\t\n",a[i].pid,a[i].bt,a[i].wt,a[i].tat);
}
}
