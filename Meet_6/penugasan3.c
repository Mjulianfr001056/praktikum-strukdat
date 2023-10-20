#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node Tnode;

struct node{
	int data;
	Tnode* next;
};

typedef Tnode* ptrnode;

typedef struct stack Tstack;

struct stack{
	ptrnode head;
	int size;
};

typedef Tstack* ptrstack;

ptrnode createNode(int nilai){
	ptrnode new_node = (ptrnode) malloc(sizeof(Tnode));
	
	new_node->data = nilai;
	new_node->next = NULL;
	
	return new_node;
}

void stack_init(ptrstack s){
	s->head = NULL;
	s->size = 0;
}

bool stack_isEmpty(ptrstack s){
	return (s->size == 0);
}

void stack_push(ptrstack s, int nilai){
	ptrnode new_node = createNode(nilai);
	
	if(stack_isEmpty(s)){
		s->head = new_node;
		s->size = 1;
	}else{
		new_node->next = s->head;
		s->head = new_node;
		++s->size; 
	}
}

void stack_pop(ptrstack s){
	//mengecek apakah size s = 0?
	if(!stack_isEmpty(s)){
		ptrnode tmp = s->head;
		
		//mengecek apakah size s = 1?
		if(tmp->next != NULL){
			s->head = tmp->next;
			tmp->next = NULL;
		}else{
			s->head = NULL;
		}
		
		free(tmp);
		--s->size;
	}
}

int stack_top(ptrstack s){
	return s->head->data;
}

void konversi(int n, ptrstack s){
	if(n>0){
		stack_push(s, n%2);
		konversi(n/2, s);
	}	
}

void konversiOktal(int n, ptrstack s){
	if(n>0){
		stack_push(s, n%8);
		konversiOktal(n/8, s);
	}
}

int main(){
	ptrstack my_stack = malloc(sizeof(Tstack));
	stack_init(my_stack);
	
	int bil_desimal;
	
	printf("Program konversi Desimal ke Biner dan Oktal\n\n");
	printf("Masukkan bilangan desimal = ");
	scanf("%d", &bil_desimal);
	
	printf("\nMenu: \n");
	printf("1. Ubah menjadi biner  = \n");
	printf("2. Ubah menjadi oktal  = \n");
	printf("Pilih menu: ");
	
	int _menu;
	scanf("%d", &_menu);
	
	switch(_menu){
		case 1 : 
			if(bil_desimal == 0) printf("Hasil konversi ke biner = 0\n");
			else{
				konversi(bil_desimal, my_stack);
				
				printf("Hasil konversi ke biner = ");
				
				while(!stack_isEmpty(my_stack)){
					printf("%d", stack_top(my_stack));
					
					stack_pop(my_stack);
				}
				
				printf(" (2)");
			}
			break;
		case 2 : 
			if(bil_desimal == 0) printf("Hasil konversi ke oktal = 0\n");
			else{
				konversiOktal(bil_desimal, my_stack);
				
				printf("Hasil konversi ke oktal = ");
				
				while(!stack_isEmpty(my_stack)){
					printf("%d", stack_top(my_stack));
					
					stack_pop(my_stack);
				}
				
				printf(" (8)");
			}
			break;
		default :
			printf("Perintah tidak diketahui, mengakhiri program...\n");
	}
	
}
