#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* make_memo(int size){
	int* memo = (int*)malloc(sizeof(int) * size);
	for(int i =0; i<size; i++){
		memo[i] = 0;
	}

	return memo;
}

int findUglyNum(int* primes, int size_of_prime, int n){
	if(n==1) return 1;

