#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* bellman_ford(int V, int** weight_matrix, int source) {
    int* track_array = (int*)malloc(sizeof(int) * V);

    for (int i = 0; i < V; i++)
        track_array[i] = INT_MAX;
    track_array[source] = 0;

    for (int k = 0; k < V - 1; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (track_array[i] != INT_MAX && weight_matrix[i][j] != INT_MAX) {
                    int new_dist = track_array[i] + weight_matrix[i][j];
                    if (new_dist < track_array[j]) {
                        track_array[j] = new_dist;
                    }
                }
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (track_array[u] != INT_MAX && weight_matrix[u][v] != INT_MAX &&
                track_array[u] + weight_matrix[u][v] < track_array[v]) {
                printf("Graph contains negative weight cycle\n");
                free(track_array);
                return NULL;
            }
        }
    }

    return track_array;
}

int main() {
    int V = 4;
    int** matrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        matrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            matrix[i][j] = INT_MAX;
    }

    matrix[0][1] = 1;  
    matrix[1][2] = -1;  
    matrix[2][0] = -1;  
    matrix[2][3] = 2;   

    int* result = bellman_ford(V, matrix, 0);

    if (result != NULL) {
        for (int i = 0; i < V; i++) {
            if (result[i] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }

    for (int i = 0; i < V; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}

