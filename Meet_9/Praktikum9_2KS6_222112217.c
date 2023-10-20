#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node Tnode;

struct node{
	int data;
	Tnode 
		*left, *right;
	int height;
};

typedef Tnode* ptrnode;

int max(int a, int b){
	return (a > b) ? a : b;
}

int getHeight(ptrnode N){
	if(!N) return 0;
	return N->height;
}

int getBalanceFactor(ptrnode N){
	if(!N){
		return 0;
	}
	
	return getHeight(N->left) - getHeight(N->right);
}

ptrnode rightRotate(ptrnode T){
	ptrnode new_root = T->left;
	ptrnode orphan = new_root->right;
	
	new_root->right = T;
	T->left = orphan;
	
	T->height = max(getHeight(T->left), getHeight(T->right))+1;
	new_root->height = max(getHeight(new_root->left), getHeight(new_root->right))+1;
	
	return new_root;
}

ptrnode leftRotate(ptrnode T){
	ptrnode new_root = T->right;
	ptrnode orphan = new_root->left;
	
	new_root->left = T;
	T->right = orphan;
	
	T->height = max(getHeight(T->left), getHeight(T->right))+1;
	new_root->height = max(getHeight(new_root->left), getHeight(new_root->right))+1;
	
	return new_root;
}
ptrnode newNode(int data){
	ptrnode new_node = (ptrnode) malloc(sizeof(Tnode));
	
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->height = 1;
	
	return new_node;
}

ptrnode insertAVL(ptrnode root, int data){
	if(!root){
		return newNode(data);
	}
	
	if(data < root->data){
		root->left = insertAVL(root->left, data);
	}else if(data > root->data){
		root->right = insertAVL(root->right, data);
	}
	
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	
	int balance = getBalanceFactor(root);
	
	if(balance>1 && data < root->left->data){
		return rightRotate(root);
	}
	
	if(balance<-1 && data > root->right->data){
		return leftRotate(root);
	}
	
	if(balance<-1 && data < root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	if(balance>1 && data > root->left->data){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	return root;
}

void displayPO(ptrnode node){
	if (!node){
		return;
	}
	
	printf("%d ", node->data);
	displayPO(node->left);
	displayPO(node->right);
}

void displayIO(ptrnode node){
	if (!node){
		return;
	}
	
	displayIO(node->left);
	printf("%d ", node->data);
	displayIO(node->right);
}

void displayPsO(ptrnode node){
	if (!node){
		return;
	}
	
	displayPsO(node->left);
	displayPsO(node->right);
	printf("%d ", node->data);
}

void search_node(ptrnode root, int data){
	ptrnode cursor = root;
	
	while(cursor->data != data){
		if (cursor){
			if(data>cursor->data){
				cursor = cursor->right;
			}else{
				cursor = cursor->left;
			}
			
			if(!cursor){
				printf("\nNode %d tidak ditemukan", data);
			}
		}
	}
	
	printf("\nNode %d ditemukan", data);
	return;
}

ptrnode delete_node(ptrnode root, int deletedData){
	if(!root) return root;

	ptrnode cursor;
		if(deletedData > root->data)
			root->right = delete_node(root->right,deletedData);
	else if(deletedData < root->data)
		root->left = delete_node(root->left, deletedData);
	else{
	
		if(root->left == NULL){
			cursor = root->right;
			free(root);
			root = cursor;
		}
		else if(root->right == NULL) {
			cursor = root->left;
			free(root);
			root = cursor;
		}
	
		else{
			cursor = root->right;
			while(cursor->left != NULL){
				cursor = cursor->left;
			}
		
			root->data = cursor->data;
			root->right = delete_node(root->right, cursor->data);
		}
	}

	if (root == NULL)
		return root;
	
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	
	int balance = getBalanceFactor(root);

	if (balance > 1 && getBalanceFactor(root->left) >= 0)
		return rightRotate(root);
	
	if (balance < -1 && getBalanceFactor(root->right) <= 0)
		return leftRotate(root);
	
	if (balance < -1 && getBalanceFactor(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	if (balance > 1 && getBalanceFactor(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	return root;
}

typedef struct item Titem;

struct item{
	ptrnode data;
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

ptritem createNode(ptrnode nilai){
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

ptrnode queue_front(ptrqueue q){
	return q->front->data;
}

void queue_push(ptrqueue q, ptrnode nilai){
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

int main(){
	
	ptrnode root = NULL;
	
	root = insertAVL(root, 9);
	root = insertAVL(root, 5);
	root = insertAVL(root, 10);
	root = insertAVL(root, 0);
	root = insertAVL(root, 6);
	root = insertAVL(root, 11);
	root = insertAVL(root, -1);
	root = insertAVL(root, 1);
	root = insertAVL(root, 2);
	
//	root = delete_node(root, 13);
//	root = delete_node(root, 3);
//	root = delete_node(root, 10);
	
//	displayPO(root); 
//	printf("\n");
//	
//	displayIO(root); 
//	printf("\n");
//	
//	displayPsO(root); 
//	printf("\n");
	
	printf("Print terurut : ");
	ptrqueue my_queue = (ptrqueue) malloc(sizeof(Tqueue));
	queue_init(my_queue);
	
	queue_push(my_queue, root);
	
	while(!queue_isEmpty(my_queue)){
		ptrnode cursor = queue_front(my_queue);
		queue_pop(my_queue);
		
		if(cursor->left){
			queue_push(my_queue, cursor->left);
		}
		
		if(cursor->right){
			queue_push(my_queue, cursor->right);
		}
		
		printf("%d ", cursor->data);
	}

	return 0;
}
