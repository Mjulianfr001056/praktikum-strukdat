#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node Tnode;
typedef struct DoublyLinkedList DLL;

struct node{
	int data;
	Tnode* next;
	Tnode* prev;
};

struct DoublyLinkedList{
	Tnode* head;
	Tnode* tail;
	int size;
};

Tnode* createNode (int node_data){
	Tnode* tmpNode = (Tnode*) malloc(sizeof(Tnode));
	
	tmpNode->data = node_data;
	tmpNode->next = NULL;
	tmpNode->prev = NULL;
	
	return tmpNode;
}

void DLL_init(DLL* currDLL){
	currDLL->head = NULL;
	currDLL->tail = NULL;
	currDLL->size = 0;		
}

void DLL_pushback(DLL* currDLL, int data){
	Tnode* newNode = createNode(data);
	
	if(currDLL->head == NULL){
		currDLL->head = newNode;
		currDLL->tail = newNode;
	}else{
		Tnode* tmpNode = (Tnode*) malloc(sizeof(Tnode));
		tmpNode = currDLL->tail;
		
		tmpNode->next = newNode;
		newNode->prev = tmpNode;
		
		currDLL->tail = newNode;
	}
}

void DLL_pushfront(DLL* currDLL, int data){
	Tnode* newNode = createNode(data);
	
	if(currDLL->head == NULL){
		currDLL->head = newNode;
		currDLL->tail = newNode;
	}else{
		Tnode* tmpNode = (Tnode*) malloc(sizeof(Tnode));
		tmpNode = currDLL->head;
		
		newNode->next = tmpNode;
		tmpNode->prev = newNode;
		
		currDLL->head = newNode;
	}
}

void DLL_print(DLL* currDLL){
	Tnode* currNode = (Tnode*) malloc(sizeof(Tnode));
	
	currNode = currDLL->head;
	
	while(currNode->next != NULL){
		printf("%d ", currNode->data);
		currNode = currNode->next;
	}
	
	printf("%d ", currNode->data);
}

void DLL_printRev(DLL* currDLL){
	Tnode* currNode = (Tnode*) malloc(sizeof(Tnode));
	
	currNode = currDLL->tail;
	
	while(currNode->prev != NULL){
		printf("%d ", currNode->data);
		currNode = currNode->prev;
	}
	
	printf("%d ", currNode->data);
}

int main(){
	DLL myList;
	
	DLL_init(&myList);
	
	DLL_pushback(&myList, 2);
	DLL_pushfront(&myList, 10);
	DLL_pushback(&myList, 99);
	DLL_pushfront(&myList, 104);
	DLL_pushback(&myList, 17);
	DLL_pushfront(&myList, 11);
	DLL_pushback(&myList, 1);
	DLL_pushfront(&myList, 4);
	
	DLL_print(&myList);
	printf("\n");
	DLL_printRev(&myList);
}
