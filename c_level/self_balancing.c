#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int data;
	int height;
} TreeNode;

int max(int a, int b){
	return (a>b)?a:b;
}

int mod(int a){
	if(a<0) return 0-a;
	else return a;
}

int calculate_depth(TreeNode* head){
	if(!head) return -1;
	if(head->left == NULL && head->right == NULL) return 0;
	return 1+max(calculate_depth(head->left), calculate_depth(head->right));
}

int calculate_bf(TreeNode* one, TreeNode* two){
	return (calculate_depth(one) - calculate_depth(two));
}

TreeNode* left_rotate(TreeNode* node){
	TreeNode* node_right = node->right;
	TreeNode* shift_node = node_right->left;

	node_right->left = node;
	node -> right = shift_node;

	return node_right;
}

TreeNode* right_rotate(TreeNode* node){
	TreeNode* node_left = node->left;
	TreeNode* shift_node = node_left->right;

	node_left->right = node;
	node->left = shift_node;

	return node_left;
}


