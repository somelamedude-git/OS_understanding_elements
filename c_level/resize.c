#include <stdio.h>

int**** resized_matrix(int** matrix_one, int** matrix_two, int rows, int cols){
	if(rows != cols){
		return null;
	}

	int size_required = rows/2;
	int**** resized_container = new int***[size_required];

	for(int i =0; i<size_required; i++){
		int** resized_arr = new int*[2];
		resized_container[i] = resized_arr;
	}

	for(int i =0; i<rows; i++){
		for(int j =0; j<cols; j++){
			resized_container[i][j/2]

}
