#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** make_memo(int rows, int cols){
	int** memo = (int**)malloc(sizeof(int*)*rows);
	for(int i =0; i<rows; i++){
		memo[i] = (int*)malloc(sizeof(int)*cols);
	}

	for(int i =0; i<rows; i++){
		for(int j =0; j<cols; j++){
			memo[i][j] = -1;
		}
	}
	return memo;
}


int count_paths(int m, int n, int** memo, int i, int j){
	if(i>=m || j>=n) return 0;
	if(memo[i][j] != -1) return memo[i][j];
	if(i==m-1 && j==n-1) return 1;

	memo[i][j] = count_paths(m,n,memo,i+1,j) + count_paths(m,n, memo,i,j+1);
}

int main(){
	int** memo = make_memo(3,3);
	printf("%d\n", count_paths(3,3,memo,0,0));
}

