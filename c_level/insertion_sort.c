#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sort(int* arr, int size){
	int key = -1;
	for(int j =1; j<size; j++){
		key = arr[j];
		int i = j-1;

		while(i>=0 && arr[i]>key){
			arr[i+1] = arr[i];
			i = i-1;
		}

		arr[i+1] = key;
	}
}

int main(){
	int arr[9] = {21, 3, 4, 12, 9, 54, 7, 12, 10};
	sort(arr, 9);

	for(int i =0; i<9; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}

