#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int count_paths(int m, int n, int i, int j){
	if(i>=m || j>=n) return 0;
	if(i==m-1 && j == n-1) return 1;

	return count_paths(m,n,i+1,j) + count_paths(m,n,i,j+1);
}


int main(){
	printf("%d\n", count_paths(3,3, 0, 0));
	return 0;
}
