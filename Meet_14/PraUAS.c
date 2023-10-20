#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node Tnode;
typedef struct SinglyLinkedList SLL;

//Membuat Node dari Linked List
struct node{
	char data[20];
	Tnode* next;
};

//Membuat Linked List
struct SinglyLinkedList{
	Tnode* head;
	unsigned size;
};

Tnode* createNode (char node_data[]){
	Tnode* tmpNode = (Tnode*) malloc(sizeof(Tnode));
	
	strcpy(tmpNode->data, node_data);
	tmpNode->next = NULL;
	
	return tmpNode;
}

void SLL_init(SLL* tmpList){
	tmpList->head = NULL;
	tmpList->size = 0;
}

void SLL_pushback(SLL* currList, char currData[]){
	Tnode* newNode = createNode(currData);
	
	if(currList->head == NULL){
		currList->size++;
		currList->head = newNode;
	}else{
		Tnode* tmp = currList->head;
		
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		
		tmp->next = newNode;
	}
}

void SLL_pushfront(SLL* currList, char currData[]){
	Tnode* newNode = createNode(currData);
	
	if(currList->head == NULL){
		currList->size++;
		currList->head = newNode;
	}else{
		newNode->next = currList->head;
		
		currList->head = newNode;
	}
}

void SLL_insertAt(SLL* currList, char currData[], int pos){
	Tnode* newNode = createNode(currData);
	
	if(currList->head == NULL){
		currList->size++;
		currList->head = newNode;
	}else{
		Tnode* currNode = (Tnode*) malloc(sizeof(Tnode));
		
		currNode = currList->head;
		
		int i;
		
		for(i = 0; i<pos; i++){
			currNode = currNode->next;
		}
		
		Tnode* tmp = (Tnode*) malloc(sizeof(Tnode));
		
		tmp->next = currNode->next;
		newNode->next = tmp->next;
		currNode->next = newNode;
	}
}

void SLL_printNode(SLL* currList){
	Tnode* currNode = (Tnode*) malloc(sizeof(Tnode));
	
	currNode = currList->head;
	
	while(currNode->next != NULL){
		printf("%s ", currNode->data);
		currNode = currNode->next;
	}
	
	printf("%s ", currNode->data);
}

/* Yang ditulis di kertas yang ini ajaaa (104~140)*/

void swap(struct node *a, struct node *b)
{   
    char temp[20];
    strcpy(temp, a->data);
    strcpy(a->data,b->data);
    strcpy(b->data,temp);
}

void bubbleSort(SLL* currList)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    if(currList->head == NULL)
        return;
    else do
    {
        swapped = 0;
        ptr1 = currList->head;
        while(ptr1->next != lptr)
        {   
        //    printf("Now comparing %s and %s \n", ptr1->data, ptr1->next->data);
        //    printf("The result of strcmp() is %d \n", strcmp(ptr1->data, ptr1->next->data));
            if (strcmp(ptr1->data, ptr1->next->data) > 0 )
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            //    printf("Swap %s and %s\n", ptr1->data, ptr1->next->data);
            //    SLL_printNode(currList);
            //    printf("\n\n");
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped == 1);
}

/*Yang ditulis di kertas yang ini ajaaa (104~140)*/

int main(){
    SLL daftar;
	
	SLL_init(&daftar);

    int i, j;
    int max = 5;
    char temp[20] = "";

    for(i = 0; i<max; i++){
        scanf("%s", &temp);
        SLL_pushback(&daftar,temp);
    }

    SLL_printNode(&daftar);

    printf("\n");
    bubbleSort(&daftar);

    SLL_printNode(&daftar);
}