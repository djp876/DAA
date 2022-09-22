/* 7.	For a weighted directed Graph, find shortest distances between every pair of vertices. (Floyds) */

Floyd's algorithm

#include<stdio.h>

int n,cost[10][10],A[10][10];

void floyds(int cost[10][10],int A[10][10],int n)

{

    int i,j,k,min;

    for(i=1;i<=n;i++)

    {

        for(j=1;j<=n;j++)

        A[i][j]=cost[i][j];

    }

    for(k=1;k<=n;k++)

    {

        for(i=1;i<=n;i++)

        {

            for(j=1;j<=n;j++)

            {

                if(A[i][k]+A[k][j]<A[i][j])

                A[i][j]=A[i][k]+A[k][j];

            }

        }

    }

    printf("The shortest paths are:\n");

   for(i=1;i<=n;i++)

   {

       for(j=1;j<=n;j++){

          printf("%d\t",A[i][j]);

       }

       printf("\n");

   }

}

int main()

{

    int i,j;

    printf("Enter no.of vertices:");

    scanf("%d",&n);

    printf("Enter cost matrix\n");

    for(i=1;i<=n;i++)

    {

        for(j=1;j<=n;j++)

        scanf("%d",&cost[i][j]);

    }

    floyds(cost,A,n);

    return 0;

}
