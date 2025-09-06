#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minSumPath(int rows, int cols, int** grid, int i, int j){
	if(grid[i][j] == -1) return __INT_MAX__;
	if(i == rows-1 && j == cols-1) return grid[i][j];

	int cost_down = (i+1<rows) ? minSumPath(rows, cols, grid, i+1, j) : __INT_MAX__;
	int cost_right = (j+1<cols)? minSumPath(rows, cols, grid, i, j+1): __INT_MAX__;

	return grid[i][j] + (cost_down<cost_right ? cost_down: cost_right);
}

int main() {
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

    int result = minSumPath(rows, cols, grid, 0, 0);

    if(result == __INT_MAX__)
        printf("No valid path exists.\n");
    else
        printf("Minimum path sum = %d\n", result);

    
    for(int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    return 0;
}
