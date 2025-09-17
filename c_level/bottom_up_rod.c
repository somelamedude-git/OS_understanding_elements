#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b){
        return (a>b)?a:b;
}

int* make_memo(int size){
	int* memo = (int*)malloc(sizeof(int) * size);
	for(int i =0; i<size; i++) memo[i] = -1;

	return memo;
}



int optRodCut(int* price, int length, int* memo){
	if(memo[length-1] != -1) return memo[length-1];
        if(length == 0) return 0;
	int optimal_cut = -1;
        int sum = INT_MIN;
        for(int i = 1; i<=length; i++){ // The length of the material that we have
                int money_ = optRodCut(price, length-i, memo) + price[i-1];
                if(money_>sum){
			sum = money_;
			optimal_cut = i;
		}
        }

	memo[length-1] = sum;
	printf("%d -> %d\n", length, optimal_cut);
        return sum;
}

int main() {
    int n = 40;

    // Example prices: price[i] = i+1 for simplicity
    int price[40];
    for(int i = 0; i < 40; i++){
        price[i] = i + 1; // price of rod length i+1
    }

    int* memo = make_memo(n); // create memoization array

    int result = optRodCut(price, n, memo);
    printf("Maximum revenue for rod of length %d = %d\n", n, result);

    free(memo); // free allocated memory
    return 0;
}

