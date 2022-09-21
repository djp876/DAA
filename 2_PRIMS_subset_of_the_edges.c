/* 2.	Given a weighted undirected graph. Finds a subset of the edges that forms a tree that includes every
vertex, where the total weight of all the edges in the tree is minimized by using prims approach. */

#include<stdio.h>
int main()
{
int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
float wtavg, tatavg;
printf("Enter the number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i] = i;
printf("Enter the Burst Time of Process%d:", i);
scanf("%d",&bt[i]);
printf("System/User Process (0/1) ? ");
scanf("%d", &su[i]);
}
for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(su[i] > su[k])
{
temp=p[i];
p[i]=p[k];
p[k]=temp;
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=su[i];
su[i]=su[k];
su[k]=temp;
}
wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\nPROCESS\tS/U\tBURST\tWAITING\tTURNAROUND");
for(i=0;i<n;i++)
printf("\n%d\t%d\t%d\t%d\t%d",p[i],su[i],bt[i],wt[i],tat[i]);
printf("\nAverage Waiting Time is --- %.2f\n",wtavg/n);
printf("Average Turnaround Time is --- %.2f\n",tatavg/n);
return 0;
}
