#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue{
	int rear;
	int front;
	int* arr;
	int size;
} queue;

queue* createQueue(int size){
	queue* q = (queue*)malloc(sizeof(queue));
	q->rear = -1;
	q->front = -1;
	q->size = -1;

	q->arr = (int*)malloc(sizeof(int) * size);

	return q;
}

void push_back(queue* q, int elem) {
    if (q->rear == q->size - 1) {
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = elem;
}

int pop(queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return -1;
    }
    int val = q->arr[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return val;
}

bool isEmpty(queue* q) {
    return (q->front == -1);
}

int orange_rot(int** matrix, int rows, int cols){
	queue* q = createQueue(rows*cols);
	int marked[rows*cols];
	int time_taken = 0;

	for(int i =0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(matrix[i][j] ==2 || matrix[i][j] == 0){
				marked[i*cols+j] = 1;
			if(matrix[i][j] == 2){
				push_back(q, i*cols+j);
			}
			}
		}
	}

	while(!isEmpty(q)){
		int value = pop(q);
		int i = value/cols;
		int j = value%cols;

		bool change = false;

		if(i-1 >=  0){
			if(matrix[i-1][j] == 1 && marked[(i-1)*cols + j] == 0){
				marked[(i-1)*cols + j] = 1;
				push_back(q, (i-1)*cols+j);
				change = true;
			}
		}

		if(i+1<rows){
			if(matrix[i+1][j] == 1 && marked[(i+1)*cols+j] == 0){
				marked[(i-1)*cols+j] = 1;
				push_back(q, (i+1)*cols+j);
				change = true;
			}
		}

		if(j-1 >=0){
			if(matrix[i][j-1] == 1 && marked[(i*cols + (j-1))] == 0){
				marked[(i*cols + (j-1))] = 1;
				push_back(q, (i*cols + (j-1)));
				change = true;
			}
		}

		if(j+1<cols){
			if(matrix[i][j+1] == 1 && marked[i*cols + (j+1)] == 0){
				marked[i*cols + (j+1)] = 1;
				push_back(q, (i*cols + (j+1)));
				change = true;
			}
		}

		if(change){
			time_taken++;
		}
	}

	for(int i =0; i<rows*cols; i++){
		if(marked[i] == 0){
			return -1;
		}
	}

	return time_taken;
}


