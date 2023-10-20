#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node Tnode;
typedef struct SinglyLinkedList SLL;

//Membuat Node dari Linked List
struct node{
	int data;
	Tnode* next;
};

//Membuat Linked List
struct SinglyLinkedList{
	Tnode* head;
	unsigned size;
};

Tnode* createNode (int node_data){
	Tnode* tmpNode = (Tnode*) malloc(sizeof(Tnode));
	
	tmpNode->data = node_data;
	tmpNode->next = NULL;
	
	return tmpNode;
}

void SLL_init(SLL* tmpList){
	tmpList->head = NULL;
	tmpList->size = 0;
}

void SLL_pushback(SLL* currList, int currData){
	Tnode* newNode = createNode(currData);
	
	if(currList->head == NULL){
		currList->size++;
		currList->head = newNode;
	}else{
		Tnode* tmp = currList->head;
		
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		
		tmp->next = newNode;
	}
}

void SLL_pushfront(SLL* currList, int currData){
	Tnode* newNode = createNode(currData);
	
	if(currList->head == NULL){
		currList->size++;
		currList->head = newNode;
	}else{
		newNode->next = currList->head;
		
		currList->head = newNode;
	}
}

void SLL_insertAt(SLL* currList, int currData, int pos){
	Tnode* newNode = createNode(currData);
	
	if(currList->head == NULL){
		currList->size++;
		currList->head = newNode;
	}else{
		Tnode* currNode = (Tnode*) malloc(sizeof(Tnode));
		
		currNode = currList->head;
		
		int i;
		
		for(i = 0; i<pos; i++){
			currNode = currNode->next;
		}
		
		Tnode* tmp = (Tnode*) malloc(sizeof(Tnode));
		
		tmp->next = currNode->next;
		newNode->next = tmp->next;
		currNode->next = newNode;
	}
}

void SLL_printNode(SLL* currList){
	Tnode* currNode = (Tnode*) malloc(sizeof(Tnode));
	
	currNode = currList->head;
	
	while(currNode->next != NULL){
		printf("%d ", currNode->data);
		currNode = currNode->next;
	}
	
	printf("%d ", currNode->data);
}


int main(){
	SLL myList;
	
	SLL_init(&myList);
	
	SLL_pushback(&myList, 1);
	SLL_pushfront(&myList, 14);
	SLL_pushback(&myList, 99);
	SLL_pushfront(&myList, 90);
	SLL_pushback(&myList, 101);
	SLL_insertAt(&myList, 10, 0);
	
	SLL_printNode(&myList);
}
