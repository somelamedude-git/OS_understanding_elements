#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int dest;
	struct Node* next;
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


int main(){
	Graph* graph = createGraph(8);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 5);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 7);
	addEdge(graph, 7, 6);
	addEdge(graph, 2, 6);

	int visited_array[8] = {0};
	depth_search(graph, 0, visited_array);

	return 0;
}



