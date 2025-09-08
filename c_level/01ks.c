#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b){
	return (a>b)?a:b;
}
int knapsack(int* values, int* weight, int limit, int size, int i){
    if(limit <= 0 || i >= size) return 0;

    int take = 0;
    if(weight[i] <= limit) 
        take = values[i] + knapsack(values, weight, limit - weight[i], size, i + 1);

    int not_take = knapsack(values, weight, limit, size, i + 1);

    return max(take, not_take);
}


int main(){

	int weights[5] = {10,20,30,30,70};
	int values[5] = {18, 24, 66, 77, 21};

	int limit = 100;

	printf("%d\n", knapsack(values, weights, limit, 5, 0));
	return 0;
}




