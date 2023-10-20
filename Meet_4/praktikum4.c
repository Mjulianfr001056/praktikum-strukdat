#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node* ptrnode;

ptrnode createNode(int nilai){
	ptrnode p;
	
	p = (ptrnode) malloc(sizeof(struct node));
	p->data = nilai;
	p->next = NULL;
	return(p);
}

void printList(ptrnode currNode){
	if(currNode){
		printf("%d ", currNode->data);
		printList(currNode->next);
	}
}

ptrnode insert_head(ptrnode head, int nilai){
	ptrnode new_node = createNode(nilai);
	new_node->next = head;
	head = new_node;
	return head;	
}

ptrnode insert_tail(ptrnode head, int nilai){
	ptrnode tail = head;
	
	while(tail->next) tail = tail->next;
	
	ptrnode new_node = createNode(nilai);
	
	tail->next = new_node;
	
	return head;
}	

ptrnode insert_after(ptrnode head, int nilai, int prev_nilai){
	ptrnode cursor = head;
	
	while(cursor->data != prev_nilai) cursor = cursor->next;
	
	ptrnode new_node = createNode(nilai);
	
	new_node->next = cursor->next;
	cursor->next = new_node;
	
	return head;
}

ptrnode insert_before(ptrnode head, int nilai, int next_nilai){
	if(head->data == next_nilai){
		head = insert_head(head, nilai);
	}else{
		ptrnode cursor, prevcursor;
		cursor = head;
		do{
			prevcursor = cursor;
			cursor = cursor->next;
		}while(cursor->data != next_nilai);
		
		ptrnode new_node = createNode(nilai);
		new_node->next = cursor;
		prevcursor->next = new_node;
	}
	
	return head;
}

ptrnode remove_first(ptrnode head){
	if(!head){
		return;
	}
	
	ptrnode first = head;
	
	head = head->next;
	first->next = NULL;
	
	free(first);
	return head;
}

ptrnode remove_last(ptrnode head){
	if(!head){
		return;
	}
	
	ptrnode cursor = head;
	ptrnode prevcursor = NULL;
	
	while(cursor->next){
		prevcursor = cursor;
		cursor = cursor->next;	
	}
	
	prevcursor->next = NULL;
	free(cursor);
	return head;
	
}

ptrnode remove_middle(ptrnode head, int nilai){
	ptrnode cursor = head;
	while(cursor){
		if(cursor->next->data == nilai) break;
		cursor = cursor->next;
	}
	
	if(cursor){
		ptrnode tmp = cursor->next;
		cursor->next = tmp->next;
		tmp->next = NULL;
		
		free(tmp);
	}
	
	return head;
}

ptrnode dispose(ptrnode head){
	if(!head) {
		return;
	}

	while(head != NULL){
		
		ptrnode tmp = head;

		head = head->next;
		tmp->next = NULL;
		
		free(tmp);
		
	}
	
	printf("Semua node telah dihapus\n");
	return head;
}

//void printPointer(ptrnode currNode){
//	if(currNode){
//		printf("%d ", currNode);
//		printPointer(currNode->next);
//	}
//}

int main(){
	ptrnode head = NULL;
	head = (ptrnode) malloc(sizeof(struct node));
	
	head->data = 10;
	head->next = NULL;
	
	//cara pertama untuk membuat simpul di linked list
	struct node node_dua;
	ptrnode dua = &node_dua;
	
	dua->data = 20;
	dua->next = NULL;
	
	head->next = dua;
	
	//cara kedua untuk membuat simpul di linked list
	ptrnode tiga = NULL;
	ptrnode empat = NULL;
	
	tiga = (ptrnode) malloc(sizeof(struct node));
	empat = (ptrnode) malloc(sizeof(struct node));
	
	dua->next = tiga;
	
	tiga->data = 30;
	tiga->next = empat;
	
	empat->data = 40;
	empat->next = NULL;
	
	//cara ketiga untuk membuat simpul di linked list (generalisasi)
	ptrnode lima = createNode(50);
	empat->next = lima;
	
	//menampilkan hasil linked list
	printList(head);
	printf("\n");
	
	//menambahkan simpul ke kiri (insert kiri)
	head = insert_head(head, 99);
	printList(head);
	printf("\n");
	
	//menambahkan simpul ke kanan (insert kanan)
	head = insert_tail(head, 11);
	printList(head);
	printf("\n");
	
	//menambahkan simpul setelah simpul tertentu (insert after)
	head = insert_after(head, 60, 50);
	printList(head);
	printf("\n");
	
	//menambahkan simpul sebelum simpul tertentu (insert before)
	head = insert_before(head, 35, 40);
	printList(head);
	printf("\n");
	
	//menghapus simpul awal (remove first)
	head = remove_first(head);
	printList(head);
	printf("\n");
	
	//menghapus simpul akhir (remove last)
	head = remove_last(head);
	printList(head);
	printf("\n");	
	
	//menghapus simpul tengah (remove middle)
	head = remove_middle(head, 30);
	printList(head);
	printf("\n");
	
	//menghapus linkedlist (dispose)
	
//	printPointer(head);
	printf("\n");
	
	head = dispose(&head);
	
	printf("%d", head);
	//printList(head);

}
