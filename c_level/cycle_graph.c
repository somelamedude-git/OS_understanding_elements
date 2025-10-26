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
	graph->array= (adjList*)malloc(sizeof(adjList) * V);

	return graph;
}

void addEdge(int dest, int src, Graph* graph){
	Node* node = newNode(dest);
	node->next = graph->array[src].head;
	graph->array[src].head = node;

	node = newNode(src);
	node->next = graph->array[dest].head;
	graph->array[dest].head = node;
}

typedef struct pair{
	int a;
	int b;
} pair;

typedef struct queue{
	int rear;
	int front;
	pair* arr;
	int size;
} queue;

queue* initQueue(int size){
	queue* q = (queue*)malloc(sizeof(queue));
	q->size = size;
	q->front = 0;
	q->rear = -1;
	q->arr = (pair*)malloc(sizeof(pair) * size);

	return q;
}

bool isEmpty(queue* q){
	if(q->front > q->rear) return true;
	return false;
}

void push_back(pair elem, queue* q){
	if(q->rear == q->size-1) return;
	q->rear++;
	q->arr[q->rear] = elem;
}

pair pop(queue* q){
	if(isEmpty(q)){
		pair empty;
		empty.a = -1;
		empty.b = -1;
		return empty;
	}
	pair temp = q->arr[q->front];
	q->front++;
	return temp;
}

bool has_cycle(Graph* graph, int source_node){
	int visited_array[graph->V];
	for(int i =0; i<graph->V; i++){
		visited_array[i] = 0;
	}

	queue* q = initQueue(graph->V);
	pair temp;
	temp.a = source_node; temp.b = -1;
	push_back(temp, q);

	while(!isEmpty(q)){
		pair weneed = pop(q);
		if(visited_array[weneed.a] == 0){
			printf("%d ", visited_array[weneed.a]);
			visited_array[weneed.a] = 1;
		}

		Node* node = graph->array[weneed.a].head;
		while(node){
			if(visited_array[node->dest] == 0){
				printf("%d ", node->dest);
				pair topush;
				topush.a = node->dest;
				topush.b = weneed.a;
				visited_array[node->dest] = 1;
				push_back(topush, q);
			}

			else if(visited_array[node->dest] == 1){
				if(node->dest != weneed.b) return true;
			}
			node = node->next;
		}
	}
	return false;
}

int main(){
	Graph* graph = createGraph(7);
	addEdge(0, 1, graph);
	addEdge(0, 2, graph);
	addEdge(1, 4, graph);
	addEdge(2, 5, graph);
	addEdge(2, 3, graph);
	addEdge(4, 6, graph);
	addEdge(5, 6, graph);

	if(has_cycle(graph, 0)){
		printf("YES\n");
	}
	return 0;
}
