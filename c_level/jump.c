#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int a, int b){
	return (a>b)?b:a;
}

int* make_memo(int size){
	int* memo = (int*)malloc(sizeof(int) * size);
	for(int i =0; i<size; i++) memo[i] = -1;
	return memo;
}

bool canJump(int* nums, int size, int current_index, int* memo){
	if(current_index == size-1) return true;
	if(nums[current_index] == 0) return false;
	if(memo[current_index] != -1) return memo[current_index];
	int loop_iter = min(size, current_index+nums[current_index]);
	bool result = false;
	for(int i = current_index+1; i<=loop_iter; i++){
		result = result | canJump(nums, size, i, memo);
	}

	memo[current_index] = (int)result;

	return result;
}

int main(){
	int nums[4] = {1,0,8,0};
	int* memo = make_memo(4);
	if(canJump(nums, 4, 0, memo))printf("yes\n");
	else printf("no\n");
	return 0;
}

		
