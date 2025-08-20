#include <stdio.h>

int**** resized_matrix( int** matrix, int rows, int cols){
	if(rows != cols){
		return NULL;
	}

	int size_required = rows/2;
	int**** resized_container =(int****) malloc(size_required* sizeof(int***));

	for(int i =0; i<size_required; i++){
		int** resized_arr = (int**)malloc(sizeof(int*) *2);
		resized_container[i] = resized_arr;
	}

	for(int i =0; i<rows; i++){
		for(int j =0; j<cols; j=j+2){
			int* arr = (int*) malloc(sizeof(int)*2);
			arr[0] = matrix

	

}
