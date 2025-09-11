#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int** make_memo(int rows, int cols){
	int** memo = (int**)malloc(sizeof(int*) * rows);
	
	for(int i =0; i<rows; i++){
		memo[i] = (int*)malloc(sizeof(int) * cols);
	}

	for(int i =0; i<rows; i++){
		for(int j =0; j<cols; j++){
			memo[i][j] = -1;
		}
	}

	return memo;
}

int ks(int* weights,int capacity, int* values, int i){
	if(capacity == 0) return 0;
	if(i == -1) return 0;
	int take = INT_MIN;
	int not_take = INT_MIN;
	int answer = INT_MIN;

	if(weights[i] <= capacity){
		take = ks(weights, capacity-weights[i], values, i-1) + values[i];
		not_take = ks(weights, capacity, values,  i-1);
	}

	else{
		not_take = ks(weights, capacity, values,  i-1);
	}

	answer = max(take, not_take);

	return answer;
}

int main(){
	int capacity = 12;
	int weights[5] = {6,7,1,2,3};
	int values[5] = {4, 8, 9, 1, 2};

	int answer = ks(weights, capacity, values, 4);

	printf("%d\n", answer);
}
