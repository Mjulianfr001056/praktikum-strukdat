#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node Tnode;

struct node{
	int data;
	Tnode 
		*left, *right;
};

typedef Tnode* ptrnode;

ptrnode newNode(int data){
	ptrnode new_node = (ptrnode) malloc(sizeof(Tnode));
	
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	
	return new_node;
}

ptrnode insertBST(ptrnode root, int data){
	if(!root){
		root = newNode(data);
	}
	else{
		bool is_left = false;
		ptrnode cursor = root;
		ptrnode prev = NULL;
		
		while(cursor){
			prev = cursor;
			if(data < cursor->data){
				is_left = 1;
				cursor = cursor->left;
			}else if (data > cursor->data){
				is_left = 0;
				cursor = cursor->right;
			}
		}
		
		if(is_left){
			prev->left = newNode(data);
		}else{
			prev->right = newNode(data);
		}
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
	if(!root) return;
	
	ptrnode cursor;
	if(deletedData > root->data)
		root->right = delete_node(root->right, deletedData);
	if(deletedData < root->data)
		root->left = delete_node(root->left, deletedData);
	else{
		if(!root->left && !root->right){
			//
		}
		if(root->left == NULL){
			cursor = root->right;
			free(root);
			root = cursor;
		} else if (root->right == NULL){
			cursor = root->left;
			free(root);
			root = cursor;
		}else{
			cursor = root->right;
			while(cursor->left){
				cursor=cursor->left;
			}
			root->data = cursor->data;
			root->right = delete_node(root->right, cursor->data);
		}
	}
	return root;
}
int main(){
	
	ptrnode root = newNode(8);
	
	root = insertBST(root, 3);
	root = insertBST(root, 1);
	root = insertBST(root, 6);
	root = insertBST(root, 4);
	root = insertBST(root, 7);
	root = insertBST(root, 10);
	root = insertBST(root, 14);
	root = insertBST(root, 13);
	
//	root = delete_node(root, 13);
	root = delete_node(root, 3);
	
	displayPO(root); 
	printf("\n");
	
	displayIO(root); 
	printf("\n");
	
	displayPsO(root); 
	printf("\n");
	
//	search_node(root,6);
//	printf("\n");
//	search_node(root,100);
	return 0;
}
