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

int calcMinHp(int** grid, int rows, int cols, int i, int j, int curr_points){
	if(i == rows || j == cols) return INT_MAX;
	if(i==rows-1 && j == cols-1){
		if(grid[i][j] > 0) return 0;
		else{
			if(curr_points+grid[i][j]>=1) return 0;
			else{
				return abs(curr_points + grid[i][j]) + 1;
			}
		}
	}
	 if(grid[i][j] >= 0) new_curr_points = curr_points + grid[i][j];
        else new_curr_points = 1;

	int right = calcMinHp(grid, rows, cols, i, j+1, new_curr_points);
	int down = calcMinHp(grid,rows, cols, i+1, j, new_curr_points);
	int points_added = 0;
	int new_curr_points;

	if(grid[i][j]<0){
		if(curr_points+grid[j][j] < 1){
			points_added = abs(grid[i][j] + curr_points)+1;
		}
	}

	int final = min(right, down)+points_added;

	return final;
}



