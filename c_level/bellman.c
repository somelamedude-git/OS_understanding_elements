#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int* bellman_ford(int V, int** weight_matrix, int source){
	int* track_array = (int*)malloc(sizeof(int) * V);

	track_array[source] = 0;
	for(int i =0; i<V; i++){
		track_array[i] = weight_matrix[source][i];
	}

	for(int k =0; k<V-1; k++){
		for(int i =0; i<V; i++){
			for(int j =0; j<V; j++){
				if(track_array[i] != INT_MAX && weight_matrix[i][j] != INT_MAX){
					int new_dist = track_array[i] + weight_matrix[i][j];
					if(new_dist<track_array[j]){
						track_array[j] = new_dist;
					}
				}
			}
		}
	}

	    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (weight_matrix[u][v] != INT_MAX) {
                if (track_array[u] + weight_matrix[u][v] < track_array[v]) {
                    printf("Graph contains negative weight cycle\n");
            
                    return NULL;
                }
            }
        }
    }

	return track_array;
}

int main(){
	int V = 6;
int** matrix = (int**)malloc(V * sizeof(int*));
for (int i = 0; i < V; i++) {
    matrix[i] = (int*)malloc(V * sizeof(int));
    for (int j = 0; j < V; j++)
        matrix[i][j] = INT_MAX;  // No connection by default
}

matrix[0][1] = 5;
matrix[0][2] = 3;
matrix[1][2] = 2;
matrix[1][3] = 6;
matrix[2][3] = 7;
matrix[3][4] = 4;
matrix[4][5] = 2;

int* result = bellman_ford(V, matrix, 0);
for(int i =0; i<V; i++){
	printf("%d ", result[i]);
}
return 0;
}


