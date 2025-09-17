#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "random.h"
#include <time.h>

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

int ks(int* weights,int capacity, int* values, int i, int** memo, int** track){
	if(capacity == 0) return 0;
	if(i == -1) return 0;
	int take = INT_MIN;
	int not_take = INT_MIN;
	int answer = INT_MIN;

	if(memo[i][capacity-1] != -1) return memo[i][capacity-1];

	if(weights[i] <= capacity){
		take = ks(weights, capacity-weights[i], values, i-1, memo, track) + values[i];
		not_take = ks(weights, capacity, values,  i-1, memo, track);
	}

	else{
		not_take = ks(weights, capacity, values,  i-1, memo, track);
	}

	if(take > not_take){
		track[i][capacity-1] = 1;
	}
	else{
		track[i][capacity-1] = 0;
	}

	answer = max(take, not_take);
	memo[i][capacity-1] = answer;

	return answer;
}

int final_boss(int* weights, int capacity, int* values, int size){
	int** memo = make_memo(size, capacity);
	int** track = make_memo(size, capacity);
	int answer= ks(weights, capacity, values, size-1, memo, track);

	int i = size-1;
	int c = capacity;
	    while(i >= 0 && c > 0){
        if(track[i][c-1] == 1){
            printf("%d\n", weights[i]);
            c -= weights[i];  
        }
        i--;
    }

	return answer;
}

int main(){
	int capacity = 3000;
	int* weights = generate_random_array(20);
	int* values = generate_random_array(20);

	clock_t start, end;
	double cpu_time_used;
	start = clock();
	int answer = final_boss(weights, capacity, values, 20);
	end = clock();
	cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("cpu time used: %f\n", cpu_time_used);
	printf("%d\n", answer);
}
