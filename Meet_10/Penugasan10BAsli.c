#include <stdio.h>
#include <stdlib.h>
#define N 6 //misal maksimum node adalah 6

// Struktur data untuk menyimpan node pada graph
struct Node{
	int node_no;
	struct Node* next;
};

typedef struct Node *adjNode;

//Struktur data untuk menyimpan objek graph
struct Graph{
	adjNode head[N];
};
typedef struct Graph *ptrGraph;


// Fungsi untuk inisialisasi adjacency list
ptrGraph createGraph(int n){
// alokasi memori untuk menyimpan struktur data graph
	ptrGraph graph = (ptrGraph)malloc(sizeof(struct Graph));
	
	// inisialiasi semua pointer head ke null
	for (int i = 0; i < N; i++) {
		graph->head[i] = NULL;
	}
	
	return graph;
}
	
adjNode createNode(int num){
	adjNode newNode = (adjNode)malloc(sizeof(struct Node));
	newNode->node_no = num;
	newNode->next = NULL;
	return newNode;
}

// fungsi untuk menambahkan edge
ptrGraph addEdge(ptrGraph graph, int src, int dest){

	//buat dest node
	adjNode newNode_dest = createNode(dest);
	
	if (graph->head[src] == NULL) {
		//buat dulu src nya
		adjNode newNode_src = createNode(src);
		graph->head[src] = newNode_src;
		graph->head[src]->next = newNode_dest;
	}
	else{
		//cari posisi dest node, lalu insert, seperti insert tail
		adjNode cursor = graph->head[src];
		while (cursor->next != NULL){
			cursor = cursor->next;
		}
		
		cursor->next = newNode_dest;
	}
	return graph;
}

// Fungsi print representasi adjacency list
void printGraph(ptrGraph graph){
	int i;
	for (i = 0; i < N; i++){
		if (graph->head[i] == NULL){
			printf("\n Adjacency list of vertex %d is empty", i);
		} else{
		// print node dan semua yang terhubung
			printf("\n Adjacency list of vertex %d:\n %d ", i, graph->head[i]->node_no);
			adjNode cursor = graph->head[i];
			while (cursor->next != NULL){
				cursor = cursor->next;
				printf("-> %d", cursor->node_no);
			}
			printf("\n");
		}		
	}
}

void main(){
	// membuat graph
	ptrGraph graph = createGraph(N);
	
	addEdge(graph, 0, 1);
	
	
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 0);
	addEdge(graph, 2, 1);
	addEdge(graph, 3, 2);
	addEdge(graph, 4, 5);
	addEdge(graph, 5, 4);
	
	printGraph(graph);
}
