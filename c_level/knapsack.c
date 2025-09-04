#include <stdio.h>
#include <stdlib.h>

int findMax(int a, int b){
	return (a>b)?a:b;
}
int knapsack(int w, int* profit, int* weight, int n){
	if(n==0 || w == 0) return 0;
	int pick =0;
	int notPick = knapsack(w, profit, weight, n-1);
	if(weight[n-1] <= w) pick = profit[n-1] + knapsack(w-weight[n-1], profit, weight, n-1);
return 	findMax(pick, notPick);
}

int main(){
	int n = 10;
	int weight[10] = {1,2,3,4,5,6,7,8,9,10};
	int profit[10] = {12,6,18,1,45,78,98,21,11,12};
	int w = 28;

	printf("%d ", knapsack(w, profit, weight, n));
	return 0;
}
