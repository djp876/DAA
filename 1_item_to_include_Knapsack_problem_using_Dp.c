/*1.Given a set of items, each with a weight and a value, determine the number of each item to include
in a collection so that the total weight is less than or equal to a given limit and the total value is as large as
possible. (0/1 Knapsack problem using DP) */

#include <stdio.h>
int max(int a, int b) 
{ 
return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1],
                           wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
 
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
    }
