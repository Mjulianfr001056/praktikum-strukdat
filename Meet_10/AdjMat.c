#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

#define MAX 20
int adj[MAX][MAX];
int n;

void create_graph();
void insert_node();
void delete_node(char);
void insert_edge(int, int);
void delete_edge(int, int);
void display();

int main()
{
    int choice;
    int node, origin, destin;
    create_graph();
    while(1){
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Insert a edge\n");
        printf("4. Delete a edge\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Masukkan menu: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            insert_node();
            break;
        case 2:
            printf("Enter a node to be deleted : ");
            scanf("%d", &node);
            delete_node(node);
            break;
        case 3:
            printf("Enter edge yang akan diinsert : ");
            scanf("%d %d", &origin, &destin);
            insert_edge(origin,destin);
            break;
        case 4:
            printf("Enter edge yang akan dihapus : ");
            scanf("%d %d", &origin, &destin);
            delete_edge(origin,destin);
            break;
        case 5:
            printf("\nMenampilkan graph dalam adjacency matrix: \n");
            display();
            getchar();
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
    getch();
    return 0;
}

void create_graph(){
    int i, max_edges, origin, destin;

    printf("Enter number if nodes: ");
    scanf("%d", &n);
    max_edges = n * (n - 1) / 2;

    for(i = 1; i <= max_edges; i++){
        printf("Enter edge %d (0 0 to quit) : ", i);
        scanf("%d %d", &origin, &destin);
        if((origin == 0) && (destin == 0))
            break;
        if(origin > n || destin > n || origin <= 0 || destin <= 0){
            printf("Invalid edge!\n");
            i--;
        }
        else{
            adj[origin][destin] = 1;
            adj[destin][origin] = 1;
        }
    }
}
void insert_node(){
    int i;
    n++;
    printf("The inserted node is %d\n", n);
    for(i = 1; i <= n; i++){
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
}
void delete_node(char u){
    int i, j;
    if(n == 0){
        printf("Graph is empty\n");
        return;
    }
    if(u > n){
        printf("Node tidak ditemukan pada graph\n");
        return;
    }
    for(i = u; i <= n - 1; i++)
    for(j = 1; j <= n; j++){
        adj[j][i] = adj[j][i + 1];
        adj[i][j] = adj[i + 1][j];
    }
    n--;
}
void insert_edge(int i, int j){
    if(i > n || j > n || i <= 0 || j <= 0){
        printf("Invalid edge!\n");
        i--;
    }
    else{
        adj[i][j] = 1;
        adj[j][i] = 1;
    }
}
void delete_edge(int i, int j){
    if(i > n || j > n || i <= 0 || j <= 0 || adj[i][j] == 0){
        printf("\nEdge tidak ditemukan!\n");
        return;
    }
    else{
        adj[i][j] = 0;
        adj[j][i] = 0;
        printf("\nEdge berhasi dihapus!\n");
    }
}
void display() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            printf("%4d",adj[i][j]);
        printf("\n");
    }
}