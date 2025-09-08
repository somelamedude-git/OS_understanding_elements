#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int a, int b){
	return (a>b)?b:a;
}

bool canJump(int* nums, int size, int current_index){
	if(current_index == size-1) return true;
	if(nums[current_index] == 0) return false;
	int loop_iter = min(size, current_index+nums[current_index]);
	bool result = false;
	for(int i = current_index+1; i<=loop_iter; i++){
		result = result | canJump(nums, size, i);
	}

	return result;
}

int main(){
	int nums[5] = {2, 3, 1, 1, 4};
	if(canJump(nums, 5, 0))printf("yes\n");
	else printf("no\n");
	return 0;
}

		
