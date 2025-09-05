#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int minSumPath(int rows, int cols, int** grid, int i, int j) {
    if(i == rows-1 && j == cols-1) return grid[i][j];

    int cost_down = (i+1 < rows) ? minSumPath(rows, cols, grid, i+1, j) : __INT_MAX__;
    int cost_right = (j+1 < cols) ? minSumPath(rows, cols, grid, i, j+1) : __INT_MAX__;

    return grid[i][j] + (cost_down < cost_right ? cost_down : cost_right);
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

    int result = minSumPath(rows, cols, grid, 0, 0);
    printf("Minimum sum path: %d\n", result);

    for(int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    return 0;
}
