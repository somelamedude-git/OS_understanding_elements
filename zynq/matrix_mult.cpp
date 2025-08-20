#define ROW1 4
#define COL1 4
#define ROW2 4
#define COL2 4

void matmul(unsigned short int A[ROW1][COL1], unsigned short int B[ROW2][COL2], int C[ROW1][COL2]);

void matmul(unsigned short int A[ROW1][COL1], unsigned short int B[ROW2][COL2], int C[ROW1][COL2]){
	for(int i =0; i<ROW1; i++){
		for(int k =0; k<COL2; k++){
			C[i][k] = 0;
			for(int j =0; j<ROW2; j++){
				C[i][k] += (A[i][j]*B[j][k])
			}
		}
	}
}
