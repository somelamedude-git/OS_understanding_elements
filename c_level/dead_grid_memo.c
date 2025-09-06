#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** make_matrix(int rows, int cols){
	int** memo = (int**)malloc(sizeof(int*) * rows);
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

int minSumPath(int** memo, int i, int j, int** grid, int rows, int cols){
	if(grid[i][j] == -1) return __INT_MAX__;
	if(i == rows-1 && j == cols-1) return grid[i][j];
	if(memo[i][j] != -1) return memo[i][j];

	int cost_down = (i+1<rows) ? minSumPath(memo, i+1, j, grid, rows, cols) : __INT_MAX__;
	int cost_right = (j+1<cols)? minSumPath(memo, i, j+1, grid,rows, cols): __INT_MAX__;

	memo[i][j] = grid[i][j] + (cost_down<cost_right ? cost_down: cost_right);
	return memo[i][j];
}

int main(){
	int** memo =  make_matrix(3, 3);
	    int rows = 3, cols = 3;

    int** grid = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++)
        grid[i] = (int*)malloc(cols * sizeof(int));

    int values[3][3] = {
        {1, 3, 1},
        {1, -1, 1},
        {4, 2, 1}
    };

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            grid[i][j] = values[i][j];
        }
    }

int result = minSumPath(memo, 0, 0, grid, rows, cols);
  if(result == __INT_MAX__)
        printf("No valid path exists.\n");
    else
        printf("Minimum path sum = %d\n", result);
return 0;
}
