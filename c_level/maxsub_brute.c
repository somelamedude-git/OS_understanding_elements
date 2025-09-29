#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int maxsub_sum(int* arr, int n){
	int sum = 0;
	int max_sum = INT_MIN;

	for(int i =0; i<n; i++){
		for(int j = i; j<n; j++){
			sum += arr[j];

			max_sum = max(sum, max_sum);
		}

		sum = 0;
	}

	return max_sum;
}

int main(){
	int arr[6] = {1,2,3,-1,-2,-3};
	printf("%d\n", maxsub_sum(arr, 6));

	return 0;
}
