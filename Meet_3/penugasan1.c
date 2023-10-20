#include<stdio.h>

typedef struct node node;

struct node {
	int data;
	node *next;
};


int main(){
	node A = {70, NULL};
	node B = {50, NULL};
	
	A.next = &B;
	
	node *curr;
	
	curr = &A;
	
	while(curr != NULL){  
		printf("Data saat ini: %d \n", curr->data);
		curr = curr->next;
	}
	
	return 0;
}
