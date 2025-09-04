#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* initialize_memo(int target_sum){
	int* memo = (int*)malloc(sizeof(int)*target_sum);
	for(int i =0; i<target_sum; i++){
		memo[i] = -1;
	}
	return memo;
}

bool canSum(int* memo,int size, int target_sum, int* arr){
	if(target_sum == 0) return true;
	if(target_sum<0) return false;
	if(memo[target_sum-1] == 1) return true;
	if(memo[target_sum-1] == 0) return false;

	for(int i =0; i<size; i++){
int		remainder = target_sum -arr[i];
		if(canSum(memo, size, remainder, arr)){
			memo[target_sum-1] = 1;
			return true;
		}
	}
	memo[target_sum-1] = 0;
	return false;
}

int main(){
	int target_sum = 11;
	int arr[5] = {2,2,2,2,2};
	int* memo = initialize_memo(target_sum);
	if(canSum(memo, 5, target_sum, arr)) printf("found\n");
	return 0;
}
				
