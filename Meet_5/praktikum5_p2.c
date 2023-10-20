#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

typedef struct node* ptrnode;

typedef struct DoublyLinkedList DLL;

struct DoublyLinkedList{
	ptrnode head;
	ptrnode tail;
	int capacity;
};

typedef struct DoublyLinkedList* ptrDLL;

//daftar fungsi yang tersedia
ptrnode createNode(int nilai);
ptrDLL DLL_init();
ptrDLL DLL_push(ptrDLL currDLL, int nilai);
ptrDLL DLL_pushBack(ptrDLL currDLL, int nilai);
void printList(ptrnode curr);
void printListRev(ptrnode curr);
void printDLL(ptrDLL currDLL, bool isRev);

int main(){
	int n, i, tmp;
	
	printf("Input the number of nodes : ");
	scanf("%d", &n);
	
	//inisialisasi DLL
	ptrDLL my_list;
	my_list = DLL_init();
	
	for(i = 0; i<n; i++){
		printf("Input data for node %d : ", i+1);
		scanf("%d", &tmp);
		my_list = DLL_pushBack(my_list, tmp);
	}
	
	printf("\nData entered in the list are : \n");
	printList(my_list->head);
	
	printf("Input data for the first node : ");
	scanf("%d", &tmp);
	
	my_list = DLL_push(my_list, tmp);
	
	printf("\nAfter insertion the new list are : \n");
	printList(my_list->head);
}

//implementasi fungsi
ptrnode createNode(int nilai){
	ptrnode new_node = malloc(sizeof(struct node));
	
	new_node->data = nilai;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	return new_node;
}

ptrDLL DLL_init(){
	ptrDLL newList = (ptrDLL) malloc(sizeof(DLL));
	
	newList->head = NULL;
	newList->tail = NULL;
	newList->capacity = 0;
	
	return newList;
}

ptrDLL DLL_push(ptrDLL currDLL, int nilai){
	//buat node baru
	ptrnode new_node = createNode(nilai);
	
	if(currDLL->capacity == 0){
		//push saat DLL empty
		currDLL->head = new_node;
		currDLL->tail = new_node;
		currDLL->capacity = 1;
	}else{
		
		//link node baru
		new_node->next = currDLL->head;
		currDLL->head->prev = new_node;
		
		//update nilai head dan capacity di DLL
		currDLL->head = new_node;
		
		currDLL->capacity++;
	}
	return currDLL;
}

ptrDLL DLL_pushBack(ptrDLL currDLL, int nilai){
	//buat nodenya
	ptrnode new_node = createNode(nilai);
	
	if(currDLL->capacity == 0){
		//pushback saat DLL empty
		currDLL->head = new_node;
		currDLL->tail = new_node;
		currDLL->capacity = 1;
	}else{
		//linking
		new_node->prev = currDLL->tail;
		currDLL->tail->next = new_node;
		
		//update nilai tail
		currDLL->tail = new_node;
		currDLL->capacity++;
	}
}

void printList(ptrnode curr){
	int cnt = 1;
	while(curr){
		printf("node %d : %d\n", cnt++, curr->data);
		curr = curr->next;
	}
}
