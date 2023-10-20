#include<stdio.h>
#include<stdlib.h>

typedef struct Tstack stack;
struct Tstack{
	int item[50];
	int size;
};

typedef stack* ptrstack;

//menyiapkan tumpukan kosong
void initializestack(ptrstack s) {
	s->size = 0;
}

//jika tumpukan kosong maka nilai fungsinya 1 (true),
//jika tidak 0(false)
int isEmpty(ptrstack s){
	return (s->size == 0);
}

//jika tumpukan sudah full(dlm deklarasi stack, field item
//adalah array dg jumlah elemen sebanyak 50)maka nilai
//nilai fungsinya 1, jika tidak 0
int isFull(ptrstack s){
	return (s->size == 50);
}

void push(int x, ptrstack s){
	if(isFull(s)){
		printf("Bilangan terlalu besar !\n");
	}else{
		s->item[s->size] = x;
		++(s->size);
	}
}

int pop(ptrstack s){
	if(isEmpty(s)) return 0;
	else{
		--(s->size);
		return  (s->item[s->size]);
	}
}

void konversi(int n, ptrstack s){
	if(n>0){
		push(n%2, s);
		konversi(n/2, s);
	}	
}

int main(){
	stack tumpukan;
	int bil_desimal;
	
	printf("Program konversi Desimal ke Biner \n\n");
	initializestack(&tumpukan);
	
	printf("Masukkan bilangan desimal = ");
	scanf("%d", &bil_desimal);
	
	if(bil_desimal == 0) printf("Hasil konversi ke biner = 0\n");
	else{
		konversi(bil_desimal, &tumpukan);
		
		int i;
		printf("Hasil konversi ke biner = ");
		for(i = tumpukan.size; i>0; i--){
			printf("%d", pop(&tumpukan));
		}
	}
}
