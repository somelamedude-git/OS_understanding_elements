#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int** make_matrix(int nodes){
	int** matrix = (int**)malloc(sizeof(int*) * nodes);
	for(int i =0; i<nodes; i++){
		matrix[i] = (int*)malloc(sizeof(int) *nodes);
	}

	return matrix;
}
