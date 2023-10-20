#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node *ptrnode;

ptrnode head = NULL;
int jumnode; // jumlah node

ptrnode insert(int nilai)
{
    ptrnode p, q;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    return (head);
}

void isi_data()
{
    int k;
    printf("input jumlah node: ");
    scanf("%d", &jumnode);
    for (int j = 1; j <= jumnode; j++)
    {
        printf("input data ke-%d :", j);
        scanf("%d", &k);
        head = insert(k);
    }
}

//Search descending
int search_desc(int x)
{ // x adalah nilai yang dicari
    int j = 1;
    ptrnode tmp = head;
    while (tmp != NULL && x <= tmp->value)
    {
        if (x == tmp->value)
        {
            return j;
        }
        else
        {
            tmp = tmp->next;
            j++;
        }
    }
    return -1; // jika tidak ada yang dicari return -1
}

//search ascending
int search_asc(int x)
{ // x adalah nilai yang dicari
    int j = 1;
    ptrnode tmp = head;
    while (tmp != NULL && x >= tmp->value)
    {
        if (x == tmp->value)
        {
            return j;
        }
        else
        {
            tmp = tmp->next;
            j++;
        }
    }
    return -1; // jika tidak ada yang dicari return -1
}

void bersihkan_memori()
{
    while (head != NULL)
    {
        ptrnode tmp = head;
        head = head->next;
        tmp->next = NULL;
        free(tmp);
    }
}

void main()
{
    isi_data();
    int x, ans;
    bool flag_asc;

    printf("Apakah data terurut naik ? (1 jika iya, 0 jika tidak) : ");
    scanf("%d", &x);

    flag_asc = x; 

    printf("input nilai yang mau dicari: ");
    scanf("%d", &x);
    
    ans = flag_asc ? search_asc(x) : search_desc(x);

    if (ans == -1)
        printf("data tidak ditemukan");
    else
        printf("data ditemukan di node ke-%d", x);

    bersihkan_memori();
}