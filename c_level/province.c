#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node{
	int dest;
struct	Node* next;
} Node;

typedef struct adjList{
	Node* head;
} adjList;

typedef struct Graph{
	int V;
	adjList* array;
} Graph;

Node* newNode(int dest){
	Node* node = (Node*)malloc(sizeof(Node));
	node->dest = dest;
	node->next = NULL;
	return node;
}

Graph* createGraph(int V){
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->array = (adjList*)malloc(sizeof(adjList) * V);
	return graph;
}

void addEdge(Graph* graph, int src, int dest){
        Node* node = newNode(dest);
        node->next = graph->array[src].head;
        graph->array[src].head = node;

        node = newNode(src);
        node->next = graph->array[dest].head;
        graph->array[dest].head = node;
}

void depth_search(Graph* graph, int source_dest, int visited_array[]){
	if(visited_array[source_dest] == 1) return;
	if(visited_array[source_dest] == 0){
		printf("%d ", source_dest);
		visited_array[source_dest] = 1;
	}

	adjList temp = graph->array[source_dest];
	Node* node = temp.head;

	while(node){
		depth_search(graph, node->dest, visited_array);
		node = node->next;
	}
}

int num_of_provinces(Graph* graph, int source_dest){
	int visited_array[graph->V];
	for(int i =0; i<graph->V; i++) visited_array[i] = 0;

	int provinces = 1;
	depth_search(graph, source_dest, visited_array);
	for(int i =0; i<graph->V; i++){
		if(visited_array[i] == 0){
			provinces++;
			depth_search(graph, i, visited_array);
		}
	}

	return provinces;
}

Graph* createAdjList(int** matrix, int V){
	Graph* graph = createGraph(V);

	for(int i =0; i<V; i++){
		for(int j =i+1; j<V; j++){
			if(matrix[i][j] == 1){
				addEdge(graph, i, j);
			}
		}
	}

	return graph;
}

