#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "random.h"

int min_cost(int* arr, int i, int j, int** dp_matrix){
	if(i+1 == j) return 0;
	if(dp_matrix[i][j] != -1) return dp_matrix[i][j];

	int res = INT_MAX;
	for(int k = i+1; k<j; k++){
		int curr = min_cost(arr, i, k, dp_matrix) + min_cost(arr, k, j, dp_matrix) +( arr[i] * arr[k] * arr[j]);
		res = (res>curr)?curr:res;
	}
	dp_matrix[i][j] = res;
	return res;
}

int final_boss(int* arr, int size){
	int** memo_mat = (int**)malloc(sizeof(int*)*size);
	for(int i =0; i<size; i++){
		memo_mat[i] = (int*)malloc(sizeof(int)*size);
	}
	for(int i =0; i<size; i++){
		for(int j =0; j<size; j++){
			memo_mat[i][j] = -1;
		}
	}

	return min_cost(arr, 0, size-1, memo_mat);
}

int main(){
	int* arr = generate_random_array(4);
	int res = final_boss(arr, 4);
	printf("%d\n", res);
	return 0;
}

	
