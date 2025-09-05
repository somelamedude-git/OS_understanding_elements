#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int rob(int* nums, int size, int i){
	if(i>=size) return 0;	
	int money_collected = INT_MIN;
	for(int k =i; k<size; k++){
		int ans = nums[k] + rob(nums, size, k+2);
		if(ans>money_collected) money_collected = ans;
	}
	return money_collected;
}

int main(){
	int nums[] = {2,7,9,3,1};
	int size = sizeof(nums)/sizeof(nums[0]);
	int money_collected = rob(nums, size, 0);
	printf("%d\n", money_collected);
	return 0;
}
