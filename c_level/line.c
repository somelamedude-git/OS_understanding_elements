#include <stdio.h>
#include <stdlib.h>

// We can assume a linked list has been formed of people

typedef struct Node{
    Node* next;
} Node;

// Now people will be forming a linked list with each other

int getNumInLine(Node* person){
    if(!person->next) return 1;
    else return 1 + getNumInLine(person->next);
}

Node* initNode(){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	return newNode;
}

int main(){
	Node* person_one = initNode();
	Node* person_two = initNode();
	Node* person_three = initNode();

	person_one->next = person_two;
	person_two->next = person_three;

	int index = getNumInLine(person_one);
	printf("%d", index);

	return 0;
}

