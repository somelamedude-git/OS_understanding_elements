#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode{
	int value;
	int priority;
} queueNode;

typedef struct queue{
	queueNode* elements;
	int front;
	int rear;
} queue;

queue* initQueue(int capacity){
	queue* q = (queue*)malloc(sizeof(queue));
	q->rear = -1;
	q->front = -1;
	q->elements = (queueNode*)malloc(sizeof(queueNode) *capacity);
	return q;
}

void enqueue(queueNode element, queue* pq){
	if(pq->front == pq->rear && pq->front== -1){
		pq->front++;
		pq->rear++;

		pq->elements[pq->rear] = element;
		return;
	}

	pq->rear++;
	pq->elements[pq->rear] = element;
}

int peek(queue* q){
	int highestPriority = INT_MIN; int index = -1;

	for(int i = q->front, i<=q->rear; i++){
		if(q->elements[i].priority > highestPriority || q->elements[i].priority == highestPriority && q->elements[i].value > q->elements[index].value){
			highestPriority = q->elements[i].priority;
			index = i;
		}
	}

	return index;
}

void dequeue(queue* pq){
	int index = peek(pq);
	for(int i = index; i<pq->rear; i++){
		pq->elements[i] = pq->elements[i+1];
	}
	pq->rear--;
}



