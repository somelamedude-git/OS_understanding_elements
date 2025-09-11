#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int* make_memo(int n){
	int* memo = (int*)malloc(sizeof(int) * n);
	for(int i =0; i<n; i++) memo[i] = -1;
	return memo;
}

bool isUgly(int n, int* memo){
	if(n==1) return true;
	if(memo[n-1] != -1) return memo[n-1];
	if((n%2 != 0) && (n%5 != 0) && (n%3 !=0)) return false;
	bool div_2 = false;
	bool div_3 = false;
	bool div_5 = false;

	if(n%2 == 0) div_2 = isUgly(n/2, memo);
	if(n%5 ==0 ) div_5 = isUgly(n/5, memo);
	if(n%3 == 0) div_3 = isUgly(n/3, memo);

	bool final = div_2 || div_5 || div_3;
	memo[n-1] = final?1:0;
	return final;
}

int main(){
	int* memo = make_memo(14);
	if(isUgly(14, memo)) printf("cool\n");
}
