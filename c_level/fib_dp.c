#include <stdio.h>
#include <stdlib.h>

int* assign_memo(int size){
	int* memo = (int*)malloc(sizeof(int)*size);
	for(int i =0; i<size; i++) memo[i] = -1;
	return memo;
}

int fib(int n, int* memo){
	if(n==0 || n==1) return n;
	if(memo[n] != -1) return memo[n];
	memo[n] = n+fib(n-1); 
	return memo[n];
}




