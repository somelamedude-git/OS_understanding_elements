#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Edge{
	int dest;
	int weight;
	struct Edge* next;
} Edge;

typedef struct edgeList{
	Edge* head;
} edgeList;

typedef struct Graph{
	int V;
	edgeList* arr;
} Graph;

Edge* createEdge(int dest, int weight){
	Edge* edge = (Edge*)malloc(sizeof(Edge));
	edge->dest = dest;
	edge->weight = weight;
	edge->next = NULL;

	return edge;
}

Graph* createGraph(int V){
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	
	graph->arr = (edgeList*)malloc(sizeof(edgeList)*V);
	for(int i =0; i<V; i++){
		graph->arr[i].head = NULL;
	}

	return graph;
}

void connectNodes(int from, int to, int weight, Graph* graph){
	Edge* node = createEdge(to, weight);
	node->next = graph->arr[from].head;
	graph->arr[from].head = node;
}

int find_weight(Graph* graph, int to, int from){
	if(to==from) return 0;
	Edge* search_area = graph->arr[from].head;
	while(search_area){
		if(search_area->dest == to){
			return search_area->weight;
		}
		search_area = search_area->next;
	}
	return INT_MAX;
}

int min(int a, int b){
	return (a>b)?b:a;
}

int** floyd_warshall(Graph* graph){
	int** matrix = (int**)malloc(sizeof(int*)*graph->V);
	for(int i =0; i<graph->V; i++){
		matrix[i] = (int*)malloc(sizeof(int)*graph->V);
	}

	for(int i =0; i<graph->V; i++){
		for(int j =0; j<graph->V; j++){
			if(i==j) matrix[i][j] = 0;
			else matrix[i][j] = INT_MAX;
		}
	}

	for(int i =0; i<graph->V; i++){
		for(int j =0; j<graph->V; j++){
			matrix[i][j] = find_weight(graph, j, i);
		}
	}

	for(int k =0; k<graph->V; k++){
		for(int i =0; i<graph->V; i++){
			for(int j =0; j<graph->V; j++){
				int from = i;
				int to = j;
				// we have to pass to k
				int weight_one = matrix[from][k];
				int weight_two = matrix[k][j];

				if(weight_one!=INT_MAX && weight_two!=INT_MAX){
					matrix[i][j] = min(matrix[i][j], (weight_one+weight_two));
				}

			}
		}
	}

	return matrix;
}

int main() {
    int V = 4;
    Graph* graph = createGraph(V);

    // Connect nodes (from, to, weight)
    connectNodes(0, 1, 5, graph);
    connectNodes(0, 3, 10, graph);
    connectNodes(1, 2, 3, graph);
    connectNodes(2, 3, 1, graph);
    // You can add more edges as needed

    int** dist = floyd_warshall(graph);

    printf("Shortest path matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    // Free the distance matrix
    for (int i = 0; i < V; i++) {
        free(dist[i]);
    }
    free(dist);

    // Free graph edges
    for (int i = 0; i < V; i++) {
        Edge* curr = graph->arr[i].head;
        while (curr) {
            Edge* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph->arr);
    free(graph);

    return 0;
}





