#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct pair {
    int distance;
    int node_value;
} pair;

typedef struct MinHeap {
    pair* arr;
    int capacity;
    int heap_size;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->heap_size = 0;  // start empty
    heap->arr = (pair*)malloc(sizeof(pair) * capacity);
    return heap;
}

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return (2 * i) + 1; }
int right(int i) { return (2 * i) + 2; }

void swap(pair* a, pair* b) {
    pair temp = *a;
    *a = *b;
    *b = temp;
}

void insertKey(MinHeap* heap, pair elem) {
    if (heap->heap_size == heap->capacity) {
        printf("Heap overflow!\n");
        return;
    }

    int i = heap->heap_size++;
    heap->arr[i] = elem;

    // Bubble up by comparing distances
    while (i != 0 && heap->arr[parent(i)].distance > heap->arr[i].distance) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

void decreaseKey(MinHeap* heap, int i, pair new_val) {
    heap->arr[i] = new_val;

    while (i != 0 && heap->arr[parent(i)].distance > heap->arr[i].distance) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeapify(MinHeap* heap, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap->heap_size && heap->arr[l].distance < heap->arr[smallest].distance)
        smallest = l;
    if (r < heap->heap_size && heap->arr[r].distance < heap->arr[smallest].distance)
        smallest = r;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        MinHeapify(heap, smallest);
    }
}

pair extractMin(MinHeap* heap) {
    if (heap->heap_size <= 0) {
        pair empty = {INT_MAX, -1};
        return empty;
    }

    if (heap->heap_size == 1)
        return heap->arr[--heap->heap_size];

    pair root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->heap_size - 1];
    heap->heap_size--;
    MinHeapify(heap, 0);

    return root;
}

bool isEmpty_q(MinHeap* heap){
	return (heap->heap_size == 0);
}

pair getMin(MinHeap* heap) {
    if (heap->heap_size == 0) {
        pair empty = {INT_MAX, -1};
        return empty;
    }
    return heap->arr[0];
}

void printHeap(MinHeap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->heap_size; i++)
        printf("(%d,%d) ", heap->arr[i].distance, heap->arr[i].node_value);
    printf("\n");
}

typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Node {
    Edge* edgeList;
} Node;

typedef struct Graph {
    int V;
    Node* nodes;
} Graph; // <-- fixed missing semicolon

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->nodes = (Node*)malloc(sizeof(Node) * V);

    for (int i = 0; i < V; i++) {
        graph->nodes[i].edgeList = NULL;
    }

    return graph;
}

Edge* createEdge(int dest, int weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->dest = dest;
    edge->weight = weight;
    edge->next = NULL;
    return edge;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Edge* temp = createEdge(dest, weight);
    temp->next = graph->nodes[src].edgeList;
    graph->nodes[src].edgeList = temp;
}

int* djiskta(Graph* graph, int source){
	MinHeap* heap = createHeap(graph->V*graph->V);
	int* arr = (int*)malloc(sizeof(int)*graph->V);

	for(int i =0; i<graph->V; i++){
		arr[i] = INT_MAX;
	}

	arr[source] = 0;
	pair elem;
	elem.distance = 0;
	elem.node_value = source;
	insertKey(heap, elem);

	while(!isEmpty_q(heap)){
		pair temp = extractMin(heap);
		int distance = temp.distance;
		int node_value = temp.node_value;

		Edge* edge = graph->nodes[node_value].edgeList;
		while(edge){
			if((edge->weight + distance)<arr[edge->dest]){
				arr[edge->dest] = edge->weight + distance;
				int weight = arr[edge->dest];
				int value = edge->dest;

				elem.distance = weight;
				elem.node_value = value;
				insertKey(heap, elem);
			}
			edge = edge->next;
		}
	}

	return arr;
}





