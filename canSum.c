#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canSum(int targetSum, int* arr, int size){
	if(targetSum == 0) return true;
	if(targetSum<0) return false;
	for(int i =0; i<size; i++){
int 	remainder = targetSum-arr[i];
		if(canSum(remainder, arr, size)) return true;
	}
	return false;
}

int main(){
	int targetSum = 17;
	int arr[5] = {5,2,3,1,8};
	if(canSum(targetSum, arr, 5)){
		printf("Found\n");
	}

	return 0;
}
