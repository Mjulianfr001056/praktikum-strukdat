#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node Tnode;

struct node{
	char data;
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

inline bool checkOpen(char ch){
	switch (ch) {
		case '{' :
		case '(' :
		case '[' :
			return true;
		default : 
			return false;
	}
}

bool checkValid(char ch, char ch1){
	if (ch == '{' && ch1 == '}') return true;
	if (ch == '(' && ch1 == ')') return true;
	if (ch == '[' && ch1 == ']') return true;
	return false;
}

int main(){
	ptrstack my_stack = (ptrstack) malloc(sizeof(Tstack));
	stack_init(my_stack);
	
	char str[50];
	
	printf("Input: "); scanf("%s", &str);
	
	int i;
	bool isValid = true;
	
	for(i = 0; i<strlen(str); i++){
		if(checkOpen(str[i])){
			stack_push(my_stack, str[i]);
		}else{
			if(stack_isEmpty(my_stack)) {
				isValid=false;
				break;
			}
			int ch = stack_top(my_stack);
			int ch1 = str[i];
			
			if (!checkValid(ch, ch1)){
				break;
			} else stack_pop(my_stack);
		}
	}
	
	if(!stack_isEmpty(my_stack)){
		isValid = false;
	}
	
	if(isValid){
		printf("true\n");
	}else{
		printf("false\n");
	}
}

