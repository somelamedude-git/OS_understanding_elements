#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b){
	return (a>b)?b:a;
}

int* allocate_memo(int size){
	int* memo = (int*)malloc(sizeof(int)*size);
	for(int i =0; i<size; i++) memo[i] = -1;
	return memo;
}


int min_coins(int target, int* coins, int size, int* memo){
	if(target ==0) return 0;
	if(target<0) return INT_MAX;
	if(memo[target-1] != -1) return memo[target-1];

	int minimum = INT_MAX;
	for(int i =0; i<size; i++){
		if(coins[i] <= target){
			int sub = min_coins(target-coins[i], coins, size, memo);
			if(sub != INT_MAX){
				minimum = min(sub+1, minimum);
			}
		}
	}

	memo[target-1] = minimum;

	return minimum;
}

int main() {
    int coins[] = {1, 2, 5};
    int size = sizeof(coins) / sizeof(coins[0]);
    int target = 11;
    
    int* memo = allocate_memo(target);

    int result = min_coins(target, coins, size, memo);
    if (result == INT_MAX) {
        printf("No solution exists for target %d\n", target);
    } else {
        printf("Minimum coins needed for %d = %d\n", target, result);
    }

    return 0;
}


