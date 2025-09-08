#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b){
	return a>b?a:b;
}

int cherry(int** grid, int rows, int cols, int i, int j){
	if(grid[i][j] == -1) return 0;
	if(i ==  rows-1 && j==cols-1) return grid[i][j];

	int down =(i+1<rows)? cherry(grid, rows, cols, i+1, j):INT_MIN;
	int right = (j+1<cols)?cherry(grid, rows, cols, i, j+1):INT_MIN;

	int more = max(down, right);
	return grid[i][j]+more;
}

int main(){
    int rows = 3, cols = 3;
    int arr[3][3] = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1,  1}
    };

    // allocate grid as int**
    int** grid = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        grid[i] = (int*)malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++){
            grid[i][j] = arr[i][j];
        }
    }

    int result = cherry(grid, rows, cols, 0, 0);
    if(result == INT_MIN) {
        printf("No valid path found.\n");
    } else {
        printf("Max cherries collected: %d\n", result);
    }

    // free memory
    for(int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    return 0;
}

