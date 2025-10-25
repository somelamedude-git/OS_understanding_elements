#include <stdio.h>
#include <stdlib.h>

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

	graph->array = (adjList*)malloc(sizeof(adjList)*V);
	for(int i =0; i<V; i++){
		graph->array[i].head = NULL;
	}
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


void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct Node* temp = graph->array[v].head;
        printf("\nAdjacency list of vertex %d\n head ", v);
        while (temp) {
            printf("-> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main() {
    int V = 4;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);

    printGraph(graph);

    return 0;
}
