#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b){
	return (a>b)?a:b;
}
int numBreak(int n){
	if(n==1) return 1;

	int answer = INT_MIN;
	for(int i = 1; i< n; i++){
		int num = i*numBreak(n-i);
		int num_two = i * (n-i);
		answer = max(answer, max(num, num_two));
	}

	return answer;
}

int main(){

	for(int i =1; i<=10; i++){
		printf("%d  %d\n", i, numBreak(i));
	}
	return 0;
}

		
