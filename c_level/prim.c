#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct set{
	int weight;
	int node;
	int parent;
} set;

typedef struct Edge{
	int weight;
	int dest;
	struct Edge* next;
} Edge;

Edge* newEdge(int dest, int weight){
	Edge* new = (Edge*)malloc(sizeof(Edge));
	new->dest = dest;
	new->weight = weight;
	new->next = NULL;
	
	return new;
}

typedef struct edgeList{
	Edge* head;
} edgeList;

typedef struct Graph{
	int V;
	edgeList* arr;
} Graph;

Graph* createGraph(int V){
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->arr = (edgeList*)malloc(sizeof(edgeList)*V);

	for(int i =0; i<V; i++){
		graph->arr[i].head = NULL;
	}

	return graph;
}

void createEdge(Graph* graph, int weight, int src, int dest){
	Edge* temp = newEdge(dest, weight);
	temp->next = graph->arr[src].head;
	graph->arr[src].head = temp;

	temp = newEdge(dest, src);
	temp->next = graph->arr[dest].head;
	graph->arr[dest].head = temp;
}

typedef struct MinHeap{
	int capacity;
	int size;
	set* heap;
} MinHeap;

MinHeap* createHeap(int capacity){
	MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
	heap->capacity = capacity;
	heap->size = 0;
	heap->heap = (set*)malloc(sizeof(set)*capacity);

	for(int i =0; i<capacity; i++){
		heap->heap[i] = NULL;
	}
	return heap;
}

int parent(int i){
	return (i-1)/2;
}

int right(int i){
	return ((2*i) + 2);
}

int left(int i){
	return ((2*i)+1);
}

void swap(set* a, set* b){
	set temp = *a;
	*a = *b;
	*b = temp;
}

void insertKey(set elements, MinHeap* heap){
	if(heap->capacity == heap->size) return;
	heap->heap[heap->size] = elements;
	int index = heap->size;
	heap->size++;

	while(index>0 && heap->heap[parent(index)].weight>heap->heap[index].weight){
		swap(&heap->heap[parent(index)], &heap->heap[index]);
		index = parent(index);
	}
}

void decreaseKey(MinHeap* heap, int i, set new_value){
	heap->heap[i] = new_value;
	while(i>0 && heap->heap[parent(i)].weight>heap->heap[i].weight){
		swap(&heap->heap[parent(i)], &heap->heap[i]);
		i = parent(i);
	}
}

void MinHeapify(MinHeap* heap, int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if(heap->heap[left].weight<heap->weight[smallest].weight){
		smallest = left;
	}
	if(heap->heap[right].weight<heap->weight[smallest].weight){
		smallest = right;
	}
	
	if(smallest != i){
		swap(heap->heap[smallest], heap->heap[i]);
	}
}

set extractMin(MinHeap* heap){
	set temp;
	temp.weight = -1;
	temp.node = -1;
	temp.parent =-1;

	if(heap->size==0) return temp;

	temp.weight = heap->heap[0].weight;
	temp.node = heap->heap[0].node;
	temp.parent = heap->heap[0].parent;

	set last = heap->heap[heap->size-1];
	heap->heap[0] = last;
	heap->size--;

	MinHeapify(heap, 0);
	return temp;
}

bool isEmpty_heap(MinHeap* heap){
	return (heap->size==0);
}

int prim(Graph* graph, Graph* min_span_graph){
	// We have already been given a graph, we have to convert it to a min graph
	Graph* min_span_graph = createGraph(graph->V);
	int visited[graph->V];
	int total_weight = 0;
	for(int i =0; i<graph->V; i++){
		visited[i] = -1;
	}

	MinHeap* heap = createHeap(graph->V*graph->V);
	set first;
	first.weight = 0;
	first.node = 0;
	first.parent = -1;

	insertKey(first, heap);

	while(!isEmpty_heap(heap)){
		set temp = extractMin(heap);
		if(visited[temp.node] == -1){
			visited[temp.node] = 1;
			total_weight += temp.weight;
			Edge* node = graph->arr[temp.node].head;
			if(temp.parent != -1){
				createEdge(min_span_graph, temp.weight, temp.node, temp.parent);
			while(node){
				set toInsert;
				toInsert.weight = node->weight;
				toInsert.node = node->dest;
				toInsert.parent = temp.node;

				insertKey(toInsert, heap);
				node = node->next;
			}
			}
		}
	}
	return total_weight;
}


	
	



