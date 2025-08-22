#include <stdio.h>

void add(int a, int b, int* c);

int main(){
	int a = 20;
	int b = 30;
	int c;

	add(a,b,&c);

	printf("%d", c);
	return 0;
}
