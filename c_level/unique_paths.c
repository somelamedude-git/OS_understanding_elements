#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int count_paths(int m, int n){
	if(n == 0 || m == 0) return 0;
	int initial = 1;
	return 1+count_paths(m-1,n) + count_paths(m, n-1);
}


int main(){
	printf("%d\n", count_paths(3,3));
	return 0;
}
