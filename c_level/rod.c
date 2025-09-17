#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int optRodCut(int* price, int length){
	if(length == 0) return 0;
	int sum = INT_MIN;
	for(int i = 1; i<=length; i++){ // The length of the material that we have
		int money_ = optRodCut(price, length-i) + price[i-1];
		sum = max(sum, money_);
	}

	return sum;
}

int main(){     
    int n = 40;

    // Example: set prices for rod lengths 1..40
    int price[40];
    for(int i = 0; i < 40; i++){
        price[i] = i + 1; // simple example: price of length i+1 = i+1
    }

    int result = optRodCut(price, n);
    printf("Maximum revenue for rod of length %d = %d\n", n, result);

    return 0;
}
