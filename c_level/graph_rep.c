#include <stdio.h>
#include <stdlib.h>

int** create_matrix(int nodes){
	int** matrix = (int**)malloc(sizeof(int*) * nodes);

	for(int i =0; i<nodes; i++){
		matrix[i] = (int*)malloc(sizeof(int) * nodes);
	}

	for(int i =0; i<nodes; i++){
		for(int j =0; j<nodes; j++){
			matrix[i][j] = 0;
		}
	}

	return matrix;
}
void create_connection(int i, int j, int** matrix){
	matrix[i][j] = 1;
	matrix[j][i] = 1;
}

void display_matrix(int** matrix, int nodes){
	for(int i =0; i<nodes; i++){
		for(int j=0; j<nodes; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int** matrix = create_matrix(8);
	create_connection(1, 2, matrix);
	create_connection(3, 5, matrix);
	create_connection(7, 6, matrix);

	display_matrix(matrix, 8);
	return 0;
}
