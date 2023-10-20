#include <stdio.h>
#include <stdlib.h>
#define N 6 //misal maksimum node adalah 6

// Struktur data untuk menyimpan node pada graph
struct Node{
	int node_no;
	int weight; //Menyimpan bobot
	struct Node* next;
};

typedef struct Node *adjNode;

typedef struct SinglyLinkedList SLL;

struct SinglyLinkedList{
	adjNode head;
	int capacity;
};

typedef SLL* ptrSLL;

//Struktur data untuk menyimpan objek graph
struct Graph{
	ptrSLL head[N];
	int size;
};
typedef struct Graph *ptrGraph;

adjNode createNode(int num, int w){
	adjNode newNode = (adjNode) malloc(sizeof(struct Node));
	newNode->node_no = num;
	newNode->weight = w; //Menyimpan bobot
	newNode->next = NULL;
	return newNode;
}

ptrSLL init_SLL(){
	ptrSLL newSLL = (ptrSLL) malloc(sizeof(SLL));
	
	newSLL->head = NULL;
	newSLL->capacity = 0;

	return newSLL;
}

// Fungsi untuk inisialisasi adjacency list
ptrGraph createGraph(int n){
// alokasi memori untuk menyimpan struktur data graph
	ptrGraph graph = (ptrGraph) malloc(sizeof(struct Graph));
	
	// inisialiasi semua pointer head ke null
	for (int i = 0; i < N; i++) {
		graph->head[i] = init_SLL();
	}
	
	graph->size = N;
	return graph;
}

// fungsi untuk menambahkan edge
ptrGraph addEdge(ptrGraph graph, int src, int dest, int w){
	// printf("(%d, %d, %d)\n", src, dest, w);
	//buat dest node
	adjNode newNode_dest = createNode(dest, w);
	
	if (graph->head[src]->head == NULL) {
		// printf("\tMasuk sini\n");
		//buat dulu src nya
		adjNode newNode_src = createNode(src, 0);

		graph->head[src]->head = newNode_src;
		// printf("%lld\n", graph->head[src]->head);

		graph->head[src]->head->next = newNode_dest;
	}
	else{
		// printf("\tLewat sini\n");
		//cari posisi dest node, lalu insert, seperti insert tail
		adjNode cursor = graph->head[src]->head;
		
		while (cursor->next != NULL){
			cursor = cursor->next;
		}
		
		cursor->next = newNode_dest;
	}

	graph->head[src]->capacity++;
	return graph;
}


ptrGraph removeNode(ptrGraph graph, int n){
	if (graph->size == 0) return graph;

    int i, idxNode;
    adjNode cur, tmp;

	for(i = 0; i<graph->size; i++){
		if(graph->head[i]->head->node_no == n) idxNode = i;
	}

	//Destroy SLL
    if(!graph->head[idxNode]->capacity == 0 && graph->head[idxNode]->head){
        cur = graph->head[idxNode]->head;

        while(cur != NULL){
            tmp = cur;
			cur = cur->next;
            free(tmp);
        }
    }


    graph->head[idxNode]->head = NULL;
	graph->head[idxNode]->capacity = 0;
	graph->size--;
	
    for(i = idxNode; i<graph->size; i++){
        graph->head[i]->head = graph->head[i+1]->head;
		graph->head[i]->capacity = graph->head[i+1]->capacity;
    }

    for(i = 0; i < graph->size; i++){
        if(graph->head[i]->head == NULL) continue;
        
		adjNode cursor = graph->head[i]->head->next;
        adjNode prev = graph->head[i]->head->next;

		while (cursor){
            if (cursor->node_no == n){
            	if(!cursor->next){
					prev->next = NULL;
				}else{
					prev->next = cursor->next;
					cursor->next = NULL;
				}
				free(cursor);
				graph->head[i]->capacity--;
				break;
			}
			prev = cursor;
            cursor = cursor->next;
        }
    }
    return graph;
}

// Fungsi print representasi adjacency list
void printGraph(ptrGraph graph){
	if(graph->size == 0){
		printf("\nAdjacency list is empty!\n");
	}
	
	//printf("%d\n", graph->size);
	int i;
	for (i = 0; i < graph->size; i++){
		adjNode cursor = graph->head[i]->head;
		//printf("%d\n", cursor);
		
		if (graph->head[i]->capacity == 0){
			printf("\nAdjacency list of vertex %d is empty\n", cursor->node_no);
		} else{
		// print node dan semua yang terhubung
			printf("\nAdjacency list of vertex %d:\n (%d, %d)", cursor->node_no, cursor->node_no, cursor->weight);
			
			adjNode cur = cursor;
			while (cur->next != NULL){
				cur = cur->next;
				printf("-> (%d, %d) ", cur->node_no, cur->weight);
			}

			printf("\n");
		}		
	}
}

void main(){
	// membuat graph
	ptrGraph graph = createGraph(N);
	
	addEdge(graph, 0, 1, 2);
	addEdge(graph, 1, 2, 3);
	addEdge(graph, 2, 0, 4);
	addEdge(graph, 2, 1, 1);
	addEdge(graph, 3, 2, 4);
	addEdge(graph, 4, 5, 5);
	addEdge(graph, 5, 4, 1);
	printGraph(graph);

	printf("\n-----------------------------\n");
	printf("\n Hapus Node 4 \n ");
	printf("\n-----------------------------\n");

	removeNode(graph, 4);

	printGraph(graph);

	printf("\n-----------------------------\n");
	printf("\n Hapus Node 1 \n ");
	printf("\n-----------------------------\n");
	
	removeNode(graph, 1);

	printGraph(graph);

	printf("\n-----------------------------\n");
	printf("\n Hapus Node 0 \n ");
	printf("\n-----------------------------\n");
	
	removeNode(graph, 0);

	printGraph(graph);

	printf("\n-----------------------------\n");
	printf("\n Hapus Node 5 \n ");
	printf("\n-----------------------------\n");
	
	removeNode(graph, 5);

	printGraph(graph);

	printf("\n-----------------------------\n");
	printf("\n Hapus Node 2 \n ");
	printf("\n-----------------------------\n");
	
	removeNode(graph, 2);

	printGraph(graph);

	printf("\n-----------------------------\n");
	printf("\n Hapus Node 3 \n ");
	printf("\n-----------------------------\n");
	
	removeNode(graph, 3);

	printGraph(graph);
}
