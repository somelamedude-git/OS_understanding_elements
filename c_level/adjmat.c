#include <stdio.h>
#define V 5
#include <limits.h>

void addEdge(int weight, int mat[V][V], int i, int j){
	mat[i][j] = weight;
	mat[j][i] = weight;
}

void init_mat(int mat[V][V]){
	for(int i =0; i<V; i++){
		for(int j =0; j<V; j++){
			mat[i][j] = INT_MAX;
		}
	}
}

void print_matrix(int mat[V][V]){
	for(int i =0; i<V; i++){
		for(int j =0; j<V; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int mat[V][V];
	init_mat(mat);

	addEdge(5, mat, 0, 1);
	addEdge(7, mat, 1, 2);
	addEdge(10, mat, 1, 3);
	addEdge(6, mat, 3, 4);
	addEdge(2, mat, 1, 4);

	print_matrix(mat);
}
