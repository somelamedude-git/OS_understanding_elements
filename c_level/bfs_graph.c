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

typedef struct queue{
	int size;
	int rear;
	int front;
	adjList* arr;
} queue;

queue* initQueue(int size){
	queue* q = (queue*)malloc(sizeof(queue));
	q->size = size;
	q->rear = -1;
	q->front = -1;

	q-> arr = (adjList*)malloc(sizeof(adjList)*size);
	return q;
}

void push_back(queue* q, adjList w){
	if(q->front == -1 && q->rear == -1){
		q->rear++;
		q->front++;
		q->arr[q->rear] = w;
		return;
	}

	if(q->rear == q->size-1) return;
	q->rear++;
	q->arr[q->rear] = w;
}

adjList pop(queue* q){
	adjList empty = {0};
	if(q->front == -1 && q->rear == -1) return empty;
	adjList temp = q->arr[q->front];
	q->front++;
	if(q->front == q->rear){
		q->rear = -1; q->front = -1;
	}
	return temp;
}

bool isEmpty(queue* q){
	if(q->rear==-1 && q->front==-1) return true;
	return false;
}

void bfs_trav(Graph* graph, int source_node){
	int visited_array[graph->V];
	for(int i =0; i<graph->V; i++){
		visited_array[i] = 0;
	}

	queue* track = initQueue(graph->V);
	push_back(track, graph->array[source_node]);
	visited_array[source_node] = 1;
	printf("%d ", source_node);

	while(!isEmpty(track)){
		adjList temp = pop(track);
		Node* node = temp.head;
		while(node){
			if(visited_array[node->dest] == 0){
				printf("%d ", node->dest);
				push_back(track, graph->array[node->dest]);
				visited_array[node->dest] = 1;
			}
			node = node->next;
		}
	}
}

int main(){
	Graph* graph = createGraph(8);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 5);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 5, 6);
	addEdge(graph, 5, 7);
	addEdge(graph, 3, 4);
	addEdge(graph, 6, 4);

	bfs_trav(graph, 0);
}



				



