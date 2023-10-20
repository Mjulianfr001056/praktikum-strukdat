#include<stdio.h>

typedef struct node node;

struct node {
	int data;
	node *left;
	node *right;
};

void jalan(node *curr){
	if(curr->left != NULL){
		jalan(curr->left);
	}
	
	printf("Data saat ini: %d \n", curr->data);
	
	if(curr->right != NULL){
		jalan(curr->right);
	}
}
int main(){
	node A = {70, NULL, NULL};
	node B = {50, NULL, NULL};
	node C = {30, NULL, NULL};
	node D = {40, NULL, NULL};
	node E = {35, NULL, NULL};
	
	A.left = &B;
	A.right = &C;
	B.left = &D;
	D.right = &E;
	
	node *curr;
	curr = &A;
	
	jalan(curr);
	
	return 0;
}
