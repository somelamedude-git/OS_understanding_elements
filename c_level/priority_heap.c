#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MinHeap{
	int* arr;
	int capacity;
	int heap_size;
} MinHeap;

MinHeap* createHeap(int capacity){
	MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
	heap->capacity = capacity;

	heap->arr = (int*)malloc(sizeof(int)*capacity);
	heap->size = -1;

	return heap;
}


int parent(int i){
	return (i-1)/2;
}

int left(int i){
	return (2*i)+1;
}

int right(int i){
	return (2*i)+2;
}

void insertKey(MinHeap* heap, int elem){
	if(heap->size == heap->capacity) return;
	heap->size++;

	heap->arr[heap->size] = elem;
	int elem_index = heap->size;

	while(elem_index>0 && heap->arr[parent(elem_index)] > elem){
		int temp = heap->arr[elem_index];
		heap->arr[elem_index] = heap->arr[parent(elem_index)];
		heap->arr[parent(elem_index)] = temp;
		elem_index = parent(elem_index);
	}
}

void decreaseKey(MinHeap* h, int i, int new_val){
	heap->arr[i] = new_val;
	while(i>0 && heap->arr[parent(i)]>new_val){
		int temp = new_val;
		heap->arr[i] = heap->arr[parent(i)];
		heap->arr[parent(i)] = temp;
		i = parent(i);
	}
}

void MinHeapify(MinHeap* heap, int i){
	int l = left(i);
	int r = right(i);

	int smallest = i;

	if(l<heap->size && h->arr[l]<h->arr[smallest])
		smallest = l;
	if(l<heap->size && heap->arr[r]<h->arr[smallest])
		smallest = r;

	if(smallest!=i){
		int temp = heap->arr[smallest];
		heap->arr[smallest] = heap->arr[i];
		heap->arr[i] = temp;

		MinHeapify(heap, smallest);
	}
}



