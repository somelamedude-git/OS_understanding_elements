#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int frogJump(int* heights, int size, int i, int j){
	if(i==j) return 0;
	int res = INT_MAX;
	for(int k = i+1; k<=j; k++){
		int energy = frogJump( heights, size, k, j)+ (heights[k]-heights[i]);
		res = res>energy?energy:res;
	}

	return res;
}

int main(){
	int height[4] = {4,5,6,7};
	int size = 4;
	int i =0;
	int j = 3;

	int min_jumps = frogJump(height, size, i, j);

	printf("%d\n", min_jumps);
	return 0;
}


