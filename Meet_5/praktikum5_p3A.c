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


ptrnode createNode(int nilai);

//daftar fungsi DLL yang tersedia
ptrDLL DLL_init();
ptrDLL DLL_push(ptrDLL currDLL, int nilai);
ptrDLL DLL_pushBack(ptrDLL currDLL, int nilai);
ptrDLL DLL_insertAfter(ptrDLL currDLL, int nilai, int pos);
ptrDLL DLL_insertBefore(ptrDLL currDLL, int nilai, int pos);
ptrDLL DLL_pop(ptrDLL currDLL);
ptrDLL DLL_popBack(ptrDLL currDLL);
ptrDLL DLL_delete(ptrDLL currDLL, int deleted);

int DLL_size(ptrDLL currDLL);
bool findNode(ptrDLL currDLL, int nilai);
void printList(ptrnode curr);
void printListRev(ptrnode curr);
void printDLL(ptrDLL currDLL, bool isRev);
void buatNode(ptrDLL prefix_LL);
void sisipNode(ptrDLL prefix_LL, ptrDLL fixed_LL);
void hapusNode(ptrDLL prefix_LL, ptrDLL fixed_LL);
void showPreNode(ptrDLL prefix_LL);
void showFixedNode(ptrDLL fixed_LL);
inline void printMenu();

int main(){
	
	//inisialisasi DLL
	ptrDLL fixed_LL;
	fixed_LL = DLL_init();
	
	ptrDLL prefix_LL;
	prefix_LL = DLL_init();
	
	int _menu;
	bool _isFinished;
	
	do{
		printMenu(prefix_LL);
		printf("Pilih menu: "); scanf("%d", &_menu);
		
		switch(_menu){
			case 1: 
				buatNode(prefix_LL);
				break;
			case 2:
				if(prefix_LL->capacity == 0){
					system("cls");
					printf("List node masih kosong! silakan buat terlebih dahulu!\n\n");
				}else sisipNode(prefix_LL, fixed_LL);
				break;
			case 3:
				if(fixed_LL->capacity == 0){
					system("cls");
					printf("List node masih kosong! silakan insert terlebih dahulu!\n\n");
				}else hapusNode(prefix_LL, fixed_LL);
				break;
			case 4:
				system("cls");
				showFixedNode(fixed_LL);
				break;
			case 5:
				_isFinished = true;
				break;
			default:
				printf("Masukan salah! Silakan input lagi! \n\n");
				break;
		}
	}while(!_isFinished);
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
	return currDLL;
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
	}if(currDLL->capacity == 1){
		ptrnode tmpNode = currDLL->head;
		
		currDLL->head = NULL;
		currDLL->tail = NULL;
		currDLL->capacity = 0;
		
		free(tmpNode);
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
	}if(currDLL->capacity == 1){
		ptrnode tmpNode = currDLL->head;
		
		currDLL->head = NULL;
		currDLL->tail = NULL;
		currDLL->capacity = 0;
		
		free(tmpNode);
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

ptrDLL DLL_delete(ptrDLL currDLL, int deleted){
	
	//apabila nilai pos ada di ekstrem awal dan akhir
	if(currDLL->head->data == deleted){
		currDLL = DLL_pop(currDLL);
		
	}else if(currDLL->tail->data == deleted){
		currDLL = DLL_popBack(currDLL);
	}else{
		ptrnode cursor = currDLL->head;
	
		while(cursor->data != deleted){
			cursor = cursor->next;
		}
		
		ptrnode tmp_node = cursor->prev;
		
		tmp_node->next = cursor->next;
		cursor->next->prev = tmp_node;
		
		cursor->prev = NULL;
		cursor->next = NULL;
		currDLL->capacity--;
		
		free(cursor);
	}
	
	return currDLL;
}

int DLL_size(ptrDLL currDLL){
	return currDLL->capacity;
}

bool findNode(ptrDLL currDLL, int nilai){
	ptrnode tmpNode = currDLL->head;
	
	if(currDLL->capacity == 0) return false;
	if(currDLL->capacity == 1) return tmpNode->data == nilai;
	
	while(tmpNode){
		if(tmpNode->data != nilai){
			tmpNode = tmpNode->next;
		}else{
			break;
		}
	}
	
	return !(tmpNode == NULL);
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

inline void printMenu(ptrDLL prefix_LL){
	if(prefix_LL->capacity != 0){
		printf("========================\n");
		printf("Node yang sudah dibuat: \n");
		printDLL(prefix_LL, false);
		printf("\n========================\n");
		printf("\n\n");
	}
	printf("========================\n");
	printf("Menu yang tersedia: \n");
	printf("1. Create node\n");
	printf("2. Insert node\n");
	printf("3. Delete node\n");
	printf("4. Print list\n");
	printf("5. Exit\n");
}

void buatNode(ptrDLL prefix_LL){
	int tmp;
	
	printf("\n========================\n");
	printf("Create node\n");
	printf("Masukkan data: "); scanf("%d", &tmp);

	prefix_LL = DLL_pushBack(prefix_LL, tmp);
	system("cls");
	
	printf("Buat node berhasil!\n\n");
}

void sisipNode(ptrDLL prefix_LL, ptrDLL fixed_LL){
	int _menu, _node, _pos;
	bool isFinished;
	
	system("cls");
	printf("========================\n");
	printf("Insert: ");
	printf("\n");
	do{
		printf("1. Insert head\n");
		printf("2. Insert tail\n");
		printf("3. Insert after\n");
		printf("4. Insert before\n");
		printf("5. Back\n");
		printf("Pilih menu: "); scanf("%d", &_menu);
		switch (_menu){
			case 1:
				system("cls");
				showPreNode(prefix_LL);
				printf("Pilih node: "); scanf("%d", &_node);
				
				if(!findNode(prefix_LL, _node)){
					system("cls");
					printf("Node tersebut belum dibuat!\n\n");
				}else{
					fixed_LL = DLL_push(fixed_LL, _node);
					prefix_LL = DLL_delete(prefix_LL, _node);
					
					system("cls");
					printf("Node berhasil ditambahkan!\n\n");
					
					showFixedNode(fixed_LL);
				}
				break;
			case 2:
				system("cls");
				showPreNode(prefix_LL);
				printf("Pilih node: "); scanf("%d", &_node);
			
				if(!findNode(prefix_LL, _node)){
					system("cls");
					printf("Node tersebut belum dibuat!\n\n");
				}else{
					
					fixed_LL = DLL_pushBack(fixed_LL, _node);
					prefix_LL = DLL_delete(prefix_LL, _node);
					
					system("cls");
					printf("Node berhasil ditambahkan!\n\n");
					
					showFixedNode(fixed_LL);
				}
				break;
			case 3:
				system("cls");
				showPreNode(prefix_LL);
				showFixedNode(fixed_LL);
				
				printf("Pilih node: "); scanf("%d", &_node);
				printf("Insert setelah: "); scanf("%d", &_pos);
				if(!findNode(prefix_LL, _node)){
					system("cls");
					printf("Node tersebut belum dibuat!\n\n");
				}if(!findNode(fixed_LL, _pos)){
					system("cls");
					printf("Posisi tersebut tidak ada!\n\n");
				}else{
					
					fixed_LL = DLL_insertAfter(fixed_LL, _node, _pos);
					prefix_LL = DLL_delete(prefix_LL, _node);
					
					system("cls");
					printf("Node berhasil ditambahkan!\n\n");
					
					showFixedNode(fixed_LL);
				}
				break;
			case 4:
				system("cls");
				showPreNode(prefix_LL);
				showFixedNode(fixed_LL);
				
				printf("Pilih node: "); scanf("%d", &_node);
				printf("Insert sebelum: "); scanf("%d", &_pos);
				if(!findNode(prefix_LL, _node)){
					system("cls");
					printf("Node tersebut belum dibuat!\n\n");
				}if(!findNode(fixed_LL, _pos)){
					system("cls");
					printf("Posisi tersebut tidak ada!\n\n");
				}else{
					
					fixed_LL = DLL_insertBefore(fixed_LL, _node, _pos);
					prefix_LL = DLL_delete(prefix_LL, _node);
					
					system("cls");
					printf("Node berhasil ditambahkan!\n\n");
					
					showFixedNode(fixed_LL);
				}
				break;
			case 5:
				isFinished = true;
				system("cls");
				break;
		}
	}while(!isFinished);
}

void hapusNode(ptrDLL prefix_LL, ptrDLL fixed_LL){
	int _menu, _node, _pos;
	bool isFinished;
	
	system("cls");
	printf("========================\n");
	printf("Hapus: ");
	printf("\n");
	do{	
		if(fixed_LL->capacity==0) break;
		printf("1. Delete head\n");
		printf("2. Delete tail\n");
		printf("3. Delete exact value\n");
		printf("4. Back\n");
		printf("Pilih menu: "); scanf("%d", &_menu);
		switch (_menu){
			case 1:
				system("cls");
				fixed_LL = DLL_pop(fixed_LL);
				
				printf("Node berhasil dihapus!\n\n");
					
				showFixedNode(fixed_LL);
				break;
			case 2:
				system("cls");
				fixed_LL = DLL_popBack(fixed_LL);
					
				printf("Node berhasil dihapus!\n\n");
					
				showFixedNode(fixed_LL);
				break;
			case 3:
				system("cls");
				showFixedNode(fixed_LL);
				
				printf("Pilih node: "); scanf("%d", &_node);

				if(!findNode(fixed_LL, _node)){
					system("cls");
					printf("Node tersebut tidak ada!\n\n");
				}else{
					fixed_LL = DLL_delete(fixed_LL, _node);
					
					system("cls");
					printf("Node berhasil dihapus!\n\n");
					
					showFixedNode(fixed_LL);
				}
				break;
			case 4:
				isFinished = true;
				system("cls");
				break;
		}
	}while(!isFinished);
}
void showPreNode(ptrDLL prefix_LL){
	printf("========================\n");
	printf("Node yang sudah dibuat: \n");
	printDLL(prefix_LL, false);
	printf("\n========================\n");
	printf("\n\n");
}

void showFixedNode(ptrDLL fixed_LL){
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Isi linked list saat ini: \n");
	printDLL(fixed_LL, false);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n\n");
}

//Muhammad Julian Firdaus
//222112217
