#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct item Titem;

struct item{
	int data;
	Titem* next;
};

typedef Titem* ptritem;

typedef struct queue Tqueue;

struct queue{
	ptritem front;
	ptritem rear;
	int size;
};

typedef Tqueue* ptrqueue;

ptritem createNode(int nilai){
	ptritem new_node = (ptritem) malloc(sizeof(Titem));
	
	new_node->data = nilai;
	new_node->next = NULL;
	
	return new_node;
}

void queue_init(ptrqueue q){
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

bool queue_isEmpty(ptrqueue q){
	return (q->size == 0);
}

int queue_size(ptrqueue q){
	return q->size;
}

int queue_front(ptrqueue q){
	return q->front->data;
}

void queue_push(ptrqueue q, int nilai){
	ptritem new_node = (ptritem) createNode(nilai);
	
	if(queue_isEmpty(q)){
		q->front = new_node;
		q->rear = new_node;
		q->size = 1;
	}else{
		q->rear->next = new_node;
		q->rear = new_node;
		q->size++;
	}
}

void queue_pop(ptrqueue q){
	ptritem tmp;
	
	if(!queue_isEmpty(q)){
		tmp = q->front;
		
		if(queue_size(q) == 1){
			q->front = NULL;
			q->rear = NULL;
			q->size = 0;
		}else{
			q->front = q->front->next;
		}
			free(tmp);
	}
}

void queue_display(ptrqueue q){
	ptritem cursor = q->front;
	
	if(!queue_isEmpty(q)){
		while(cursor){
			printf("%d ", cursor->data);
			cursor = cursor->next;
		};
	}else{
		printf("Antrian kosong!\n");
	}
}

int main(){
	ptrqueue my_queue = (ptrqueue) malloc(sizeof(Tqueue));
	queue_init(my_queue);
	
	int i = 0;
	for(i; i<0; i++){
		queue_push(my_queue, i);
	}
	
//	while(!queue_isEmpty(my_queue)){
//		printf("%d ", queue_front(my_queue));
//		queue_pop(my_queue);
//	}
	
	queue_display(my_queue);
	
	printf("\n");
}
