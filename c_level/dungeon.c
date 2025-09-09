#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
	int score;
	char* path;
} Result;

int** make_memo(int rows, int cols){
	int** memo = (int**)malloc(sizeof(int*)rows);
	for(int i =0; i<rows; i++){
		memo[i] = (int*)malloc(sizeof(int)*cols);
	}

	for(int i =0; i<rows; i++){
		for(int j =0; j<cols; j++){
			memo[i][j] = -1
		}
	}
	return memo;
}

int max(int a, int b){
	return (a>b)?a:b;
}

Result make_path(int score, const char* path){
	Result r;
	r.score = score;
	r.path = strdup(path);

	return r;
}

Result calculateMaxPoints(int** dungeon, int rows, int cols, int i, int j){
	if(
	Result right = calculateMaxPoints(dungeon, rows, cols, i, j+1);
	Result down = calculateMaxPoints(dungeon, rows, cols, i+1, j);

	Result optimal_path;

	if(right.score > down.score){
		char* newpath = (char*)malloc(strlen(right.path) + 2);
		newpath[0] = 'R';
		strcpy(newpath+1, right.path);

		best.score = right.score + dungeon[i][j];
		best.path = newpath;
	}

	else{
		char* newpath = (char*)malloc(strlen(down.path) + 2);
		newpath[0] = 'D';
		strcpy(newpath+1, down.path);

		best.score = down.score + dungeon[i][j];
		best.path = newpath;
	}

	return best;
}
