#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct{
	int* arr;
	int size;
	int capacity;
} MinHeap;

MinHeap* createHeap(int capacity){
	MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
	heap->arr = (int*)malloc(sizeof(int) * capacity);
	heap->size = 0;
	heap->capacity = capacity;

	return heap;
}


int parent(int i){
	return (i-1)/2;
}

int right(int i){
	return (2* (i+1));
}

int left(int i)
	return (2* (i+2));

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void insert_key(int k, MinHeap* heap){
	if(heap->size == capacity) return;
	heap->size++;
	int index = heap->size-1;
	heap->arr[index] = k;

	int i = index;

	while(i!=0 && heap->arr[parent(i)] > heap->arr[index]){
		swap(&heap->arr[i], &heap->arr[parent(i)]);
		i = parent(i);
	}
}

int extractMin(MinHeap* heap){
	if(heap->size <=0) return INT_MAX;
	if(heap->size == 1){
		heap->size--;
		return heap->arr[0];
	}

	int root = h->arr[0];

