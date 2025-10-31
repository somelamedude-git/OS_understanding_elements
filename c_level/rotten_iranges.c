#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int dest;
	int orange_type; // this can have value 0, 1, and 2
	struct Node* next;
} Node;

typedef struct adjList{
	Node* head;
} adjList;

typedef struct Graph{
	int V;
	adjList* array;
} Graph;


Node* newNode(int dest, int value){
        Node* node = (Node*)malloc(sizeof(Node));
        node->dest = dest;
        node->next = NULL;
	node->orange_type = value;

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


void addEdge(Graph* graph, int src, int orange_value_src, int orange_value_dest, int dest){
        Node* node = newNode(dest, orange_value_dest);
        node->next = graph->array[src].head;
        graph->array[src].head = node;

        node = newNode(src, orange_value_src);
        node->next = graph->array[dest].head;
        graph->array[dest].head = node;
}

typedef struct queue{
	int size;
	int front;
	int rear;
	int* arr;
} queue;

queue* initQueue(int size){
	queue* q = (queue*)malloc(sizeof(queue));
	q->size = size;
	q->front = -1;
	q->rear = -1;

	q->arr = (int*)malloc(sizeof(int)*size);
	return q;
}

void push_back(queue* q, int elem) {
    if (q->rear == q->size - 1) {
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = elem;
}

int pop(queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return -1;
    }
    int val = q->arr[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return val;
}

bool isEmpty(queue* q) {
    return (q->front == -1);
}

Graph* create_matrix_graph(int** matrix, int cols, int rows){
	Graph* graph = createGraph(rows*cols);
	for(int i =0; i<rows; i++){
 		for(int j =0; j<cols; j++){
				if(i+1 != rows){
					addEdge(graph, (i*cols + j), matrix[i][j], matrix[i+1][j],  ((i+1)*cols + j));
				}
				
				if(j+1 != cols){
					addEdge(graph, (i*cols + j), matrix[i][j], matrix[i][j+1], (i*cols + (j+1)));
				}
			}
		}

	return graph;
}

int orange_step(Graph* graph, int** matrix, int cols, int rows){
	int visited_array[rows*cols];
	int marked[cols* rows];
	int source_node = -1;
	int visited[cols*rows];

	int total_steps = 0;

	for(int i =0; i<cols*rows; i++){
		visited[i] = 0;
	}


	for(int i =0; i<rows*cols; i++){
		if(matrix[i/cols][i%cols] == 2 || matrix[i/cols][i%cols] == 0){
			if(matrix[i/cols][i%cols] == 2 && source_node == -1){
				source_node = i;
			}
			marked[i] = 1;
		}
		else{
			marked[i] = 0;
		}
	}

	queue* q = initQueue(rows*cols);
	push_back(source_node, q);
	visited[source_node] = 1;

	while(!isEmpty(q)){
		int src = pop(q);
		Node* node = graph->array[src].head;
		int rotten_value = node->orange_type;
		bool changed = false;
		while(node){
			int node_value = node->dest;
			if(visited[node_value] == 0){
				push_back(node_value, q);
				visited[node_value] = 1;
			}

			if(rotten_value == 2 && marked[node_value] == 0){
				marked[node_value] = 1;
				changed = true;
			}
			node = node->next;
		}

		if(changed){
			total_steps++;
		}
	}

	for(int i =0; i<cols*rows; i++){
		if(marked[i] == 0){
			return -1;
		}
	}

	return total_steps;
}






