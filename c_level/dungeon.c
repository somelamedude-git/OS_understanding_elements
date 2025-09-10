#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int min(int a, int b){
	return (a>b)?b:a;
}

int** make_memo(int rows, int cols){
	int** memo =(int**)malloc(sizeof(int*) * rows);
	for(int i =0; i<rows; i++){
		memo[i] = (int*)malloc(sizeof(int)*cols);
	}

	for(int i =0; i<rows; i++){
		for(int j =0; j<cols; j++) memo[i][j] = -1;
	}

	return memo;
}

int calcMinHp(int** grid, int rows, int cols, int i, int j){
	if(i==rows || j == cols) return INT_MAX;
	if(i == rows-1 && j == cols-1) return (grid[i][j]<=0)?-grid[i][j]+1 : 1;

	int right = calcMinHp(grid, rows, cols, i, j+1);
	int down = calcMinHp(grid, rows, cols, i+1, j);

	int min_health_required = min(right, down) - grid[i][j];

	return ( min_health_required <= 0 ) ? 1 : min_health_required;
}



