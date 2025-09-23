#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct treeNode{
	treeNode* left;
	treeNode* right;
	int data;
} treeNode;

treeNode* initNode(){
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->data = data;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

typedef struct queue{
	treeNode** arr;
	int front;
	int rear;
	int size;
} queue;

queue* createQueue(int size){
	queue* q = (queue*)malloc(sizeof(queue));
	q->arr = (treeNode**)malloc(size*sizeof(treeNode*));
	q->front = q->rear = 0;
	q->size = size;

	return q;
}

void setNodeData(treeNode* node, int data){
	node->data = data;
}








