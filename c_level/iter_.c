#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void find_iter_mm(int arr[], int size){
	int min_value = arr[0];
	int max_value = arr[0];

	for(int i = 1; i<size; i++){
		if(arr[i] < min_value){
			min_value = arr[i];
		}
		if(arr[i] > max_value) max_value = arr[i];
	}
	printf("%d ", min_value);
	printf("%d\n ", max_value);
}

int main(){
	int arr[8] = {1,2,3,4,5,6,7,8};
	clock_t start, end;
	double cpu_run_time;
	start = clock();
	find_iter_mm(arr, 8);
	end = clock();
	cpu_run_time = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("%f ", cpu_run_time);
}
