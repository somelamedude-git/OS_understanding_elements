#include <stdio.h>
#include <stdlib.h>

int gridTraveller(int i, int j, int** memo){
	if(i == 0 || j == 0) return 0;
	if(memo[i-1][j-1] != -1) return memo[i-1][j-1];
	if(i==1 && j==1) return 1;
	int answer;
       	answer = gridTraveller(i-1, j, memo) + gridTraveller(i, j-1, memo);
	memo[i-1][j-1] = answer;
	return answer;
}

int** initMemo(int rows, int cols){
	int** memo = (int**)malloc(sizeof(int*) * rows);
	for(int i =0; i<cols; i++){
		memo[i] = (int*)malloc(sizeof(int) * cols);
	}

	for(int i =0; i<rows; i++){
		for(int j =0; j<cols; j++){
			memo[i][j] = -1;
		}
	}

	return memo;
}

int main(){
	int** memo = initMemo(3,3);
	printf("%d\n", gridTraveller(3,3, memo));
	return 0;
}

