#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "random.h"
int* generate_random_array(int size){
	int* random_arr = (int*)malloc(size* sizeof(int));
	for(int i =0; i<size; i++){
		random_arr[i] =(int)((rand()%10) + 100);
	}

	return random_arr;
}

