#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b){
	return (a>b)?b:a;
}

int** make_memo(int rows, int cols){
	int** memo =(int**)malloc(sizeof(int*)*rows);
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

int minSum(int** grid, int rows, int cols, int i, int j){
	if(i>=rows || j>=cols) return INT_MAX;
	if(i == rows-1 && j==cols-1) return grid[i][j];
	if(memo[i][j] != -1) return memo[i][j];
	int result =  grid[i][j] + min(minSum(grid, rows, cols, i+1, j), minSum(grid, rows, cols, i, j+1));
	memo[i][j] = result;
	return result;
}


int main() {
    int rows = 3, cols = 3;

    // allocate grid
    int** grid = (int**)malloc(sizeof(int*) * rows);
    for(int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(sizeof(int) * cols);
    }

    // fill grid
    int temp[3][3] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            grid[i][j] = temp[i][j];

    int result = minSum(grid, rows, cols, 0, 0);
    printf("Minimum path sum = %d\n", result);

    // free memory
    for(int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    return 0;
}

