#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// We need to check in slices
bool subsetSumK(int size,int index, int target, int* arr){
	if(target==0) return true;
	if(index ==0) return (arr[index] == target);

	bool notTake = subsetSumK(size, index-1, target, arr);
	bool take = false;
	
	if(target>=arr[index]) take = subsetSumK(size, index-1, target-arr[index], arr);

	return notTake | take;
}

int main(){
	int arr[5] = {1,2,3,4,5};
	int K = 6;

	if(subsetSumK(5, 4, K, arr)) printf("YES\n");
	return 0;
}
