#include<stdio.h>
#include<stdlib.h>

typedef struct node Tnode;

struct node{
	int data;
	Tnode 
		*left, *right;
};

typedef Tnode* ptrnode;

ptrnode newNode(int data){
	ptrnode new_node = (ptrnode) malloc(sizeof(Tnode));
	
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	
	return new_node;
}

void displayPO(ptrnode node){
	if (!node){
		return;
	}
	
	printf("%d ", node->data);
	displayPO(node->left);
	displayPO(node->right);
}

void displayIO(ptrnode node){
	if (!node){
		return;
	}
	
	displayIO(node->left);
	printf("%d ", node->data);
	displayIO(node->right);
}

void displayPsO(ptrnode node){
	if (!node){
		return;
	}
	
	displayPsO(node->left);
	displayPsO(node->right);
	printf("%d ", node->data);
}
int main(){
	
	ptrnode root = newNode(8);
	
	root->left = newNode(3);
	root->left->right = newNode(1);
	root->left->left = newNode(6);
	root->left->right->right = newNode(4);
	root->left->right->left = newNode(7);
	
	root->right = newNode(10);
	root->right->left = newNode(14);
	root->right->left->right = newNode(13);
	
	displayPO(root); 
	printf("\n");
	
	displayIO(root); 
	printf("\n");
	
	displayPsO(root); 
	printf("\n");
	
	return 0;
}
