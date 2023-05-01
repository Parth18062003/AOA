#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int main()
{
	int n,i,W;
    printf("Enter number of items: ");
    scanf("%d",&n);
    int weight[n],profit[n];
    printf("Enter maximum capacity of knapsack: ");
    scanf("%d",&W);
	printf("Enter weights of items: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter weight of item %d: ",i+1);
	    scanf("%d",&weight[i]);
	}
	printf("Enter profit: ");
	for(i=0;i<n;i++)
	{
	    printf("Enter profit of item %d: ",i+1);
	    scanf("%d",&profit[i]);
	}
	printf("Maximum profit: %d", knapSack(W, weight, profit, n));
	return 0;
}
