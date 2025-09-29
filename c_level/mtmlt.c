#include <stdio.h>
#include <stdlib.h>

int choose(int n, int r){
	if(r==0 || n==r) return 1;

	return choose(n-1, r-1) + choose(n-1, r);
}

int main(){
	printf("%d\n", choose(5,2));
	return 0;
}
