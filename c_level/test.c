#include <stdio.h>
#include <stdlib.h>

// Your function as-is
int**** resized_matrix(int** matrix, int rows, int cols){
    if(rows != cols){
        return NULL;
    }

    int size_required = rows/2;
    int**** resized_container =(int****) malloc(size_required* sizeof(int***));

    for(int i =0; i<size_required; i++){
                for(int j = 0; j<size_required; j++){
                        int** resized_arr = (int**)malloc(sizeof(int*)*2);
                        resized_container[i][j] = resized_arr;
                }
        }


    for(int i =0; i<rows; i++){
        for(int j =0; j<cols; j=j+2){
            int* arr = (int*) malloc(sizeof(int)*2);
            arr[0] = matrix[i][j];
            arr[1] = matrix[i][j+1];

            resized_container[i][j/2][i] = arr;
        }
    }

    return resized_container;
}

// Helper to create a square matrix
int** create_matrix(int n) {
    int** mat = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            mat[i][j] = i*10 + j; // fill with distinct numbers
        }
    }
    return mat;
}

// Helper to print a 2D matrix
void print_matrix(int** mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; // example 4x4
    int** mat = create_matrix(n);

    printf("Original matrix:\n");
    print_matrix(mat, n);

    int**** resized = resized_matrix(mat, n, n);

    // Attempt to print first block element
    printf("\nResized matrix first block element (if accessible):\n");
    printf("%d %d\n", resized[0][0][0][0], resized[0][0][0][1]); // may crash

    // Free original matrix
    for(int i = 0; i < n; i++) free(mat[i]);
    free(mat);

    // Not freeing resized_matrix because allocation is inconsistent
    return 0;
}

