#include<bits/stdc++.h>
using namespace std;

typedef struct node Tnode;

struct node{
	int data;
	Tnode* left;
	Tnode* right;
};

typedef Tnode* ptrnode;
queue<ptrnode> q;

ptrnode createNode(int data){
	ptrnode new_node = (ptrnode) malloc(sizeof(Tnode));
	
	new_node->data = data;
	new_node->right = NULL;
	new_node->left = NULL;
}

int main(){
	ptrnode root = createNode(0);
	
	ptrnode satu = createNode(1);
	ptrnode dua = createNode(2);
	
	root->left = satu;
	root->right = dua;
	
	ptrnode tiga = createNode(3);
	ptrnode empat = createNode(4);
	ptrnode lima = createNode(5);
	
	satu->left = tiga;
	satu->right = empat;
	
	dua->left = lima;
	
	q.push(root);
	
	while(!q.empty()){
		ptrnode cursor = q.front();
		q.pop();
		
		if(cursor->left){
			q.push(cursor->left);
		}
		
		if(cursor->right){
			q.push(cursor->right);
		}
		
		printf("%d ", cursor->data);
	}
}
