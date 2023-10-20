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

inline void printMenu();

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
	int cnt = 1;
	
	if(!queue_isEmpty(q)){
		while(cursor){
			printf("%d. %d \n", cnt++, cursor->data);
			cursor = cursor->next;
		};
	}else{
		printf("Antrian kosong!\n");
	}
}

int main(){
	
	//inisialisasi queue
	ptrqueue my_queue = (ptrqueue) malloc(sizeof(Tqueue));
	queue_init(my_queue);
		
	int _menu, _noAntri;
	bool _isFinished, _isEnqueued;
	
	int i = 56;
	for(i; i<60; i++){
		queue_push(my_queue, i);
	}
	
	do{
		printMenu();
		printf("Pilih menu: "); scanf("%d", &_menu);
		
		switch(_menu){
			case 1:
				if(_isEnqueued){
					system("cls");
					printf("Kamu sudah memiliki nomor antrian yaitu %d\n", _noAntri);
				}else{
					_noAntri = queue_size(my_queue)+56;
					queue_push(my_queue, _noAntri);
					
					system("cls");
					printf("Kamu sekarang adalah antrian nomor: %d\n", _noAntri);
					_isEnqueued = true;
				}	
				break;
			case 2:
				system("cls");
				printf("Antrian saat ini: \n");
				queue_display(my_queue);
				break;
			case 3:
				system("cls");
				if(_isEnqueued) printf("Perkiraan waktu tunggu: %d menit\n", (queue_size(my_queue) - 1)* 15);
				else printf("Perkiraan waktu tunggu: %d menit\n", queue_size(my_queue)* 15);
				break;
			case 4:
				_isFinished = true;
				break;
			default:
				printf("Masukan salah! Silakan input lagi! \n\n");
				break;
		}
	}while(!_isFinished);
}

inline void printMenu(){
	printf("========================\n");
	printf("Menu yang tersedia: \n");
	printf("1. Ambil nomor antrian\n");
	printf("2. Cek antrian tersisa\n");
	printf("3. Cek perkiraan waktu tunggu\n");
	printf("4. Exit\n");
}

