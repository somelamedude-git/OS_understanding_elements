#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int twoPersonCollect(int rows, int cols, int** grid, int i, int j1, int j2){
	if(j1<0 || j2<0 || j1>=cols || j2>=cols) return INT_MIN;
	if(i == rows-1){
		if(j1==j2) return grid[i][j1];
		return grid[i][j1] + grid[i][j2];
	}

	int collect = (j1==j2)?grid[i][j1] : (grid[i][j1] + grid[i][j2]);
	int best = INT_MIN;
	

int maximumChocolates(int rows, int cols, int** grid){
	return personCollects(rows, cols, grid, 0, 0) + personCollects(rows, cols, grid, 0, cols-1);
}

