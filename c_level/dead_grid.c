#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minSumPath(int rows, int cols, int** grid){
	if(cols == 1 && rows==1) return grid[rows-1][cols-1];
	int cost_left;
	if(cols-1>=0) cost_left = minSumPath(rows, cols-1, grid); else cost_left = INT_MAX;
	int cost_up;
	if(rows-1>=0) cost_up = minSumPath(rows-1, cols, grid); else cost_up = INT_MAX;
	if(cost_left>cost_up) return cost_up+grid[rows-1][cols-1];
	return cost_left + grid[rows-1][cols-1];
}

int main() {
    int rows = 2;
    int cols = 3;

    int** grid = (int**)malloc(sizeof(int*) * rows);
    for(int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(sizeof(int) * cols);
    }

    grid[0][0] = 5; grid[0][1] = 9; grid[0][2] = 6;
    grid[1][0] = 11; grid[1][1] = 5; grid[1][2] = 2;

    int result = minSumPath(rows, cols, grid);
    printf("Minimum sum path: %d\n", result);

    for(int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    return 0;
}

