#include <stdio.h> 
#include <stdlib.h> 
#define N 6 //misal maksimum node adalah 6 

// Struktur data untuk menyimpan node pada graph 
struct Node{ 
    int node_no; 
    int weight;
    struct Node* next; 
}; typedef struct Node *adjNode; 

//Struktur data untuk menyimpan objek graph 
struct Graph{ 
    adjNode head[N]; 
}; typedef struct Graph *ptrGraph;
 
ptrGraph createGraph(int n){        // Fungsi untuk inisialisasi adjacency list
    ptrGraph graph = (ptrGraph)malloc(sizeof(struct Graph));        // alokasi memori untuk menyimpan struktur data graph 
    for (int i = 0; i < N; i++) {       // inisialiasi semua pointer head ke null 
        graph->head[i] = NULL; 
    } 
    return graph; 
} 

adjNode createNode(int num, int berat){ 
    adjNode newNode = (adjNode)malloc(sizeof(struct Node)); 
    newNode->node_no = num; 
    newNode->weight = berat;
    newNode->next = NULL; 
    return newNode; 
} 
 
ptrGraph addEdge(ptrGraph graph, int src, int dest, int berat){        // fungsi untuk menambahkan edge
    adjNode newNode_dest = createNode(dest, berat);        //buat dest node 
    if (graph->head[src] == NULL) { 
        adjNode newNode_src = createNode(src, berat);      //buat dulu src nya 
        graph->head[src] = newNode_src; 
        graph->head[src]->next = newNode_dest; 
    } 
    else{ 
        adjNode cursor = graph->head[src];      //cari posisi dest node, lalu insert, seperti insert tail 
        while (cursor->next != NULL){
            cursor = cursor->next; 
        } 
        cursor->next = newNode_dest; 
    } 
    return graph; 
} 

void printGraph(ptrGraph graph){            // Fungsi print representasi adjacency list 
    int i; 
    for (i = 0; i < N; i++){ 
        if (graph->head[i] == NULL){ 
            printf("\n Adjacency list of vertex %d is empty", i); 
        } 
        else{ 
            printf("\n Adjacency list of vertex %d:\n %d ", i, graph->head[i]->node_no);        // print node dan semua yang terhubung 
            adjNode cursor = graph->head[i]; 
            while (cursor->next != NULL){ 
                cursor = cursor->next; 
                printf("-> %d(%d) ", cursor->node_no, cursor->weight); 
            } printf("\n"); 
        } 
    } 
} 

ptrGraph removeNode(ptrGraph graph, int n){
    int i;
    adjNode cur, tmp;
    if(graph->head[n] != NULL){
        cur = graph->head[n];
        while(cur != NULL){
            tmp = cur->next;
            free(cur);
            cur = tmp;
        }
    }
    graph->head[n] = NULL;
    for(i = n; i <= N; i++){
        graph->head[i] = graph->head[i+1];
    }

    for(i = 0; i < N-1; i++){
        if(graph->head[i] == NULL) break;
        adjNode cursor = graph->head[i];
        while (cursor->next != NULL){
            if (cursor->next->node_no == n)
                break;
            cursor = cursor->next;
        }
     
        if(cursor != NULL){
            adjNode temp = cursor->next;
            if (temp == NULL){
                cursor->next = NULL;
            }
            else{
                cursor->next = temp->next;
                temp->next = NULL;  
            }
            free(temp); 
        }
        //break;
    }
    return graph;
}

void main(){ 
    ptrGraph graph = createGraph(N);        // membuat graph 
    addEdge(graph, 0, 1, 7);
    addEdge(graph, 1, 2, 9); 
    addEdge(graph, 2, 0, 1); 
    addEdge(graph, 2, 1, 3); 
    addEdge(graph, 3, 2, 4); 
    addEdge(graph, 4, 5, 2); 
    addEdge(graph, 5, 4, 6); 
    printGraph(graph); 

    printf("\nHapus Node 2\n");

    removeNode(graph, 2);
    
    printGraph(graph);
}