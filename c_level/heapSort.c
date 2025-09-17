#include <stdio.h>
#include <climits>
#include <stdlib.h>

typedef struct node{
	int data;
	int* right;
	int* left;
} node;

node* initNode(){
	node* root = (node*)malloc(sizeof(node));
	root->data = -1;
	root ->left = NULL;
	root->right = NULL;

	return root;
}

nnode* make_tree(int* arr, int size){

	
