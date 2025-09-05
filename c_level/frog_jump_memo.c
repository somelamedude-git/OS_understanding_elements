#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* make_matrix(int size){
	int* matrix = (int*)malloc(sizeof(int)*size);
	for(int i =0; i<size; i++){
		matrix[i] = -1;
	}
	return matrix;
}

int frog_jump(int* memo, int* arr, int size, int i, int j){
	if(memo[i] != -1) return memo[i]; // We actually will propogate backwards, help with filling crap
	if(i==j) return 0;

	int res = INT_MAX;
	for(int k = i+1; k<=j; k++){
		int energy = frog_jump(memo, arr, size, k,j)+(arr[k]-arr[i]);
		if(energy<res) res = energy;
	}
	memo[i] = res;
	return res;
}

int main() {
    int arr[] = {1, 5, 10, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i = 0, j = size - 1;

    int* memo = make_matrix(size);

    int min_energy = frog_jump(memo, arr, size, i, j);
    printf("Minimum energy from arr[%d] to arr[%d]: %d\n", i, j, min_energy);

    free(memo);
    return 0;
}
