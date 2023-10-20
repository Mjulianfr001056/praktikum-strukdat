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
ptrDLL DLL_insertAfter(ptrDLL currDLL, int nilai, int pos);
ptrDLL DLL_insertBefore(ptrDLL currDLL, int nilai, int pos);
ptrDLL DLL_pop(ptrDLL currDLL);
ptrDLL DLL_popBack(ptrDLL currDLL);
int DLL_size(ptrDLL currDLL);
void printList(ptrnode curr);
void printListRev(ptrnode curr);
void printDLL(ptrDLL currDLL, bool isRev);

int main(){
	
	//inisialisasi DLL
	ptrDLL my_list;
	my_list = DLL_init();
	
	//insert dari depan
	my_list = DLL_push(my_list, 40);
	my_list = DLL_push(my_list, 30);
	my_list = DLL_push(my_list, 20);
	my_list = DLL_push(my_list, 10);
	my_list = DLL_push(my_list, 0);

	my_list = DLL_pushBack(my_list, 50);
	my_list = DLL_pushBack(my_list, 60);
	my_list = DLL_pushBack(my_list, 70);
	my_list = DLL_pushBack(my_list, 80);
	my_list = DLL_pushBack(my_list, 90);
	
	my_list = DLL_insertAfter(my_list, 1, 0); //ekstrem awal
	my_list = DLL_insertAfter(my_list, 100, 90); //ekstrem akhir
	my_list = DLL_insertAfter(my_list, 55, 50); //middle
	
	my_list = DLL_insertBefore(my_list, -1, 0); //ekstrem awal
	my_list = DLL_insertBefore(my_list, 99, 100); //ekstrem akhir
	my_list = DLL_insertBefore(my_list, 59, 60); //middle
	
	printf("Print list\n");
	printDLL(my_list, false);
	
	printf("\nJumlah node dalam linked list: %d", DLL_size(my_list));
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

ptrDLL DLL_insertAfter(ptrDLL currDLL, int nilai, int pos){
	
	//apabila nilai pos ada di ekstrem akhir
	if(currDLL->tail->data == pos){
		currDLL = DLL_pushBack(currDLL, nilai);
	}else{
		ptrnode cursor = currDLL->head;
	
		while(cursor->data != pos){
			cursor = cursor->next;
		}
		ptrnode new_node = createNode(nilai);
		
		new_node->next = cursor->next;
		cursor->next->prev = new_node;
		
		cursor->next = new_node;
		new_node->prev = cursor;
		currDLL->capacity++;
	}
	
	return currDLL;
}

ptrDLL DLL_insertBefore(ptrDLL currDLL, int nilai, int pos){
	
	//apabila nilai pos ada di ekstrem awal
	if(currDLL->head->data == pos){
		currDLL = DLL_push(currDLL, nilai);
	}else{
		ptrnode cursor = currDLL->head;
	
		while(cursor->data != pos){
			cursor = cursor->next;
		}
		
		ptrnode new_node = createNode(nilai);
		
		new_node->next = cursor;
		new_node->prev = cursor->prev;
		
		cursor->prev->next = new_node;
		cursor->prev = new_node;
		currDLL->capacity++;
	}
	
	return currDLL;
}

ptrDLL DLL_pop(ptrDLL currDLL){
	if(currDLL->capacity == 0){
		printf("List kosong!\n");
		return currDLL;
	}else{
		ptrnode tmpNode = currDLL->head;
		
		currDLL->head = currDLL->head->next;
		
		currDLL->head->prev = NULL;
		tmpNode->next = NULL;
		currDLL->capacity--;
		
		free(tmpNode);
	}
	return currDLL;
}

ptrDLL DLL_popBack(ptrDLL currDLL){
	if(currDLL->capacity == 0){
		printf("List kosong!\n");
		return currDLL;
	}else{
		ptrnode tmpNode = currDLL->tail;
		
		currDLL->tail = currDLL->tail->prev;
		
		currDLL->tail->next = NULL;
		tmpNode->prev = NULL;
		currDLL->capacity--;
		
		free(tmpNode);
	}
	return currDLL;
}

int DLL_size(ptrDLL currDLL){
	return currDLL->capacity;
}

void printList(ptrnode curr){
	if(curr){
		printf("%d ", curr->data);
		printList(curr->next);
	}
}

void printListRev(ptrnode curr){
	if(curr){
		printf("%d ", curr->data);
		printListRev(curr->prev);
	}
}

void printDLL(ptrDLL currDLL, bool isRev){
	if(currDLL->capacity == 0){
		printf("List kosong!\n");
	}else if(isRev){
		printListRev(currDLL->tail);
	}else{
		printList(currDLL->head);
	}
}

//Muhammad Julian Firdaus
//222112217
