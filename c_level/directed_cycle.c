#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int dest;
	struct Node* next;
} Node;

typedef struct adjList{
	Node* head;
} adjList
