#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

typedef struct node* ptrnode;

ptrnode createNode(int nilai){
	ptrnode new_node = malloc(sizeof(struct node));
	
	new_node->data = nilai;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	return new_node;
}

void printList(ptrnode curr){
	if(curr){
		printf("%d ", curr->data);
		printList(curr->next);
	}
}

ptrnode find_tail(ptrnode curr){
	ptrnode tail = curr;
	
	while(tail->next){
		tail = tail->next;
	}
	
	return tail;
}

void printListRev(ptrnode head){
	
	ptrnode tail = find_tail(head);
	
	while(tail){
		printf("%d ", tail->data);
		tail = tail->prev;
	}
}

ptrnode insert_head(ptrnode head, int nilai){
	ptrnode new_node = createNode(nilai);
	
	new_node->next = head;
	head->prev = new_node;
	
	return new_node;
}

ptrnode insert_tail(ptrnode head, int nilai){
	ptrnode tail = find_tail(head);
	ptrnode new_node = createNode(nilai);
	
	tail->next = new_node;
	new_node->prev = tail;
	
	return head;
}

ptrnode insert_after(ptrnode head, int nilai, int pos){

	ptrnode cursor = head;
	
	while(cursor->data != pos){
		cursor = cursor->next;
	}
	
	ptrnode new_node = createNode(nilai);
	new_node->next = cursor->next;
	cursor->next->prev = new_node;
	
	cursor->next = new_node;
	new_node->prev = cursor;
	
	return head;
}

ptrnode insert_before(ptrnode head, int nilai, int pos){
	if(head->data == pos){
		head = insert_head(head, nilai);
	}else{
		ptrnode cursor = head;
	
		while(cursor->data != pos){
			cursor = cursor->next;
		}
		
		ptrnode new_node = createNode(nilai);
		
		new_node->next = cursor;
		new_node->prev = cursor->prev;
		cursor->prev->next = new_node;
		cursor->prev = new_node;
	}
	
	return head;
}

ptrnode delete_first(ptrnode curr){
	if(!curr){
		return NULL;
	}else{
		ptrnode tmpNode = curr;
		curr = curr->next;
		
		tmpNode->next = NULL;
		curr->prev = NULL;
		
		free(tmpNode);
		return curr;
	}
}

ptrnode delete_tail(ptrnode curr){
	if(!curr){
		return NULL;
	}else{
		ptrnode cursor = find_tail(curr);
		ptrnode tmpNode = cursor;
		
		cursor = cursor->prev;
		
		tmpNode->prev = NULL;
		cursor->next = NULL;
		
		free(tmpNode);
		
		return curr;
	}
}

ptrnode delete_middle(ptrnode head, int nilai){
	ptrnode cursor = head;
	
	if(cursor->data == nilai){
		head = delete_first(cursor);
	}else{
		
		bool flag = false;
		
		while(cursor){
			if(cursor->data == nilai) {
				flag = true;
				break;
			}
			cursor = cursor->next;
		}
		
		if(!flag){
			return head;
		}
		
		if(cursor->next){
			
			ptrnode tmp = cursor->next;
			cursor->next = tmp->next;
			tmp->next->prev = cursor;
			
			tmp->next = NULL;
			tmp->prev = NULL;
			
			free(tmp);
		}else{
			head = delete_tail(head);
		}
	}
	
	return head;
}
int main(){
	ptrnode head = NULL;
	ptrnode tail = NULL;
	
	head = (ptrnode) malloc(sizeof(struct node));
	tail = head;
	
	head->data = 10;
	
	head->next = NULL;
	head->prev = NULL;
	
	//Insert simpul kedua
	struct node node_dua;
	ptrnode dua = &node_dua;
	
	//ini create nodenya
	dua->data = 20;
	dua->next = NULL;
	dua->prev = NULL;
	
	//ini linking nya
	head->next = dua;
	dua->prev = head;
	
	//insert simpul ketiga dan keempat
	ptrnode tiga = (ptrnode) malloc(sizeof(struct node));
	ptrnode empat = (ptrnode) malloc(sizeof(struct node));
	
	//create node tiga dan empat
	tiga->data = 30;
	tiga->next = empat;
	tiga->prev = NULL;
	
	empat->data = 40;
	empat->next = NULL;
	empat->prev = tiga;
	
	//linking ke dua 	
	dua->next = tiga;
	tiga->prev = dua;
	
	//insert simpul kelima dengan generalisasi createNode;
	ptrnode lima = createNode(50);
	
	//linking 4 dan 5
	empat->next = lima;
	lima->prev = empat;
	
	//forward printing
	printList(head);
	printf("\n");
	
	//backward printing
	printListRev(head);
	printf("\n");
	
	//insert simpul dengan generalisasi insert_head()
	head = insert_head(head, 0);
	printList(head);
	printf("\n");
	
	//insert simpul dengan generalisasi insert_tail()
	head = insert_tail(head, 60);
	printList(head);
	printf("\n");
	
	//insert simpul setelah elemen tertentu insert_after()
	head = insert_after(head, 45, 40);
	printList(head);
	printf("\n");
	
	//insert simpul sebelum elemen tertentu insert_before()
	head = insert_before(head, 55, 60);
	printList(head);
	printf("\n");
	
	//delete simpul awal
	head = delete_first(head);
	printList(head);
	printf("\n");
	
	//delete simpul akhir
	head = delete_tail(head);
	printList(head);
	printf("\n");
	
	//delete simpul antara
	head = delete_middle(head, 30);
	printf("ini -> ");
	printList(head);
	
}
