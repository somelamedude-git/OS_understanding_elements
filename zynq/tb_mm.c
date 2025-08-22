#include <stdio.h>

#define ROW1 4
#define COL1 4
#define ROW2 4
#define COL2 4

void matmul(unsigned short int A[ROW1][COL1], unsigned short int B[ROW2][COL2], int C[ROW1][COL2]);

int main(){
	unsigned short int A[ROW1][COL1] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	unsigned short int B[ROW2][COL2] = {17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};

	int C[ROW1][COL2];

	matmul(A,B,C);

	 for(int i = 0; i < ROW1; i++){
        for(int j = 0; j < COL2; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

	 return 0;
}
