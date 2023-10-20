#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;
struct node* sorted = NULL;

void fill_data(int val) //insert sebagai head
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = head;
	head = newnode;
}


void sortedInsert(struct node* newnode) //insert node baru ke linked list yang sudah terurut
{
	/* Jika kosong atau ternyata headnya sorted lebih besar */
	if (sorted == NULL || sorted->data >= newnode->data) {
		newnode->next = sorted;
		sorted = newnode;
	}
	else {
		struct node* current = sorted;
		// Cari node sebelum yang akan di-insert
		while (current->next != NULL && current->next->data < newnode->data) {
			current = current->next;
		}
		newnode->next = current->next;
		current->next = newnode;
	}
}


void insertionSort()
{
	struct node* current = head;
	// Traverse linked list dan insert setiap node ke linke list sorted
	while (current != NULL) {
		struct node* next = current->next; // Simpan next dari node
		sortedInsert(current); // Insert current ke linked list sorted
		current = next; // Update current
	}
	// Update head untuk menunjuk ke sorted (head diganti sorted)
	head = sorted;
}


void selectionSort()
{
    struct node* temp = head;

    // Traverse linked list
    while(temp != NULL) {
        struct node* min = temp;
        struct node* r = temp->next;

        // Traverse bagian belum terurut, cari minimum
        while(r != NULL) {
            if (min->data > r->data)
                min = r;

            r = r->next;
        }

        // Swap data dari node temp dan min
        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
}


struct node* merge(struct node* firstNode, struct node* secondNode)
{
    struct node* merged = (struct node*)malloc(sizeof(struct node));
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    merged = temp;

    // while salah satu node menjadi NULL
    while (firstNode != NULL && secondNode != NULL) {
        if (firstNode->data < secondNode->data) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }

    // sisa node di firstNode atau secondNode di-insert ke temp
    while (firstNode != NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }

    while (secondNode != NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }

    // return head dari linked list yang terurut setelah dimerge
    return merged->next;
}

// fung untuk mengambil node tengah
struct node* middle(struct node* head)
{
    struct node* slow = head;
    struct node* fast = head->next;

    while (slow->next != NULL && (fast != NULL && fast->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


struct node* mergeSort(struct node* head)
{
    if (head->next == NULL) {
        return head;
    }

    struct node* mid = (struct node*)malloc(sizeof(struct node));
    struct node* head2 = (struct node*)malloc(sizeof(struct node));
    mid = middle(head);
    head2 = mid->next;
    mid->next = NULL; //potong jadi 2 linked list: head, head2 (head dan head2 tidak tersambung)

    //merge 2 linked list yang telah terurut
    struct node* finalhead = merge(mergeSort(head), mergeSort(head2));

    return finalhead;
}

// swap/tukar data node a dan b
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort()
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    if(head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;
        while(ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped == 1);
}


void tampil_data(struct node* head)
{
	while (head != NULL) {
		printf("%d->", head->data);
		head = head->next;
	}
	printf("NULL");
}


int main()
{

	fill_data(2);
	fill_data(3);
	fill_data(20);
	fill_data(5);
	fill_data(10);
	fill_data(7);

	printf("Linked List data sebelum diurutkan:\n");
	tampil_data(head);
	printf("\n");

	insertionSort();

	//selectionSort();

	//head = mergeSort(head);

	//bubbleSort();

	printf("Linked List data setelah diurutkan:\n");
	tampil_data(head);
}
