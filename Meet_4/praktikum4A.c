#include<stdlib.h>
#include<stdio.h>

//base component
struct node{
	int data;
	struct node* next;
};

typedef struct node* ptrnode;

ptrnode createNode(int nilai){
	ptrnode newNode = (ptrnode) malloc(sizeof(struct node));
	
	newNode->data = nilai;
	newNode->next = NULL;
	
	return newNode;
}

void printList(ptrnode currNode){
	while(currNode){
		printf("%d ", currNode->data);
		currNode = currNode->next;
	}
}

ptrnode insert_head(ptrnode head, int nilai){
	ptrnode newNode = createNode(nilai);
	
	newNode->next = head;
	return newNode;
}

ptrnode insert_tail(ptrnode head, int nilai){
	ptrnode tail = head;
	
	while(tail->next){
		tail = tail->next;
	}
	
	ptrnode new_node = createNode(nilai);
	
	tail->next = new_node;
	
	return head;
}

int main(){
	ptrnode head = NULL;
	
	head = (ptrnode) malloc(sizeof(struct node));
	
	//cara pertama memasukkan data (inisialisasi struct dulu baru dihubungkan)
	head->data = 1;
	head->next = NULL;
	
	struct node node_dua;
	ptrnode dua = &node_dua;
	
	dua->data = 2;
	dua->next = NULL;
	
	head->next = dua;
	
	//cara kedua memasukkan data (inisialisasi pointer dulu baru dihubungkan)
	ptrnode tiga = (ptrnode) malloc(sizeof(struct node));
	ptrnode empat = (ptrnode) malloc(sizeof(struct node));
	
	tiga->data = 3;
	tiga->next = empat;
	
	empat->data = 4;
	empat->next = NULL;
	
	dua->next = tiga;
	
	//cara ketiga memasukkan data (generalisasi dengan fungsi createNode() )
	ptrnode lima = createNode(5);
	
	empat->next = lima;
	
	//print linkedlist 
	printList(head);
	printf("\n");
	
	//insert di awal linkedlist
	head = insert_head(head, 0);
	printList(head);
	printf("\n");
	
	//insert di akhir linkedlist
	head = insert_tail(head, 10);
	printList(head);
	printf("\n");
	
		
}
