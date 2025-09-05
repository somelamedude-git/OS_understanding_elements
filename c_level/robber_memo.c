#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int robber(int* nums, int*memo, int i, int size){
	if(i>=size) return 0;
	if(memo[i] != -1) return memo[i];

	int money_collected = INT_MIN;
	for(int k = i; k<size; k++){
		int ans = nums[k] + robber(nums, memo, k+2, size);
		if(ans>money_collected) money_collected = ans;
	}

	memo[i] = money_collected;
	return money_collected;
}

int* make_memo(int size){
	int* memo = (int*)malloc(sizeof(int)*size);
	for(int i =0; i<size; i++)memo[i] = -1;
	return memo;
}

int main(){
	  int nums[] = {2,7,9,3,1};
        int size = sizeof(nums)/sizeof(nums[0]);
	int* memo = make_memo(size);
        int money_collected = robber(nums, memo, 0, size);
        printf("%d\n", money_collected);
        return 0;
}

