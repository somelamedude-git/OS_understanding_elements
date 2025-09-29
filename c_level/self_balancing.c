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

TreeNode* initNode(int data){
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNodde));
	TreeNode->left = NULL;
	TreeNode->right = NULL;

	TreeNode->data = data;

	return node;
}

TreeNode* insert(TreeNode* node, int key){
	if(!node) return initNode(key);

	if(key<node->data) node->left = insert(node->left, key);
	else if(key>node->data) node->right = insert(node->right, key);
	else return node;

	int balance = calculate_bf(node->left, node->right);

	if(balance > 1 && key < node->left->data) return right_rotate(node);

	if(balance < -1 && key > node->right->data) return left_rotate(node);

	if(balance > 1 && key > node->left->data){
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}

	if(balance < -1 && key < node->right->data){
		node->right = right_rotate(node->right);
		return left_rottate(node);
	}

	return node;
}

