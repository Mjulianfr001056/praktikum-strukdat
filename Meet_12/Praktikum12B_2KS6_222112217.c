#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct item
{
    int key;
    int value;
};

struct hashtable_item
{
    int flag;
    /* flag = 0 : Tidak ada data
     * flag = 1 : Ada data
     * flag = 2 : Sebelumnya ada datanya */
    struct item *data;
};

struct hashtable_item *array;
int max = 13;

/* initializing hash table array */
void init_array()
{
    int i;
    for (i = 0; i < max; i++)
    {

        array[i].flag = 0;
        array[i].data = NULL;
    }
}

/* to every key, it will generate a corresponding index */
int hashcode(int key)
{
    return (key % 13);
}

int hashcode2(int key)
{
    return (7 - (key % 7));
}

int size = 0; /* size dari hashtable */

int size_of_hashtable()
{
    return size;
}

void insert(int key, int value)
{
    if (size == max)
    {
        printf("\n Hash table is full, cannot insert any more item \n");
        return;
    }
    else
    {
        int index = hashcode(key) % max;

        /* creating new item to insert in the hash table array */
        struct item *new_item = (struct item *)malloc(sizeof(struct item));
        new_item->key = key;
        new_item->value = value;

    
        // Double Hashing
        int i = 0;

        while (array[index].flag != 0)
        {
            ++i;
            if(array[index].flag == 2){
                index = (hashcode(key) + i * hashcode2(key)) % max;
            }else if(array[index].data->key == key){
                printf("\n Key already exists, hence updating its value \n");
                array[i].data->value = value;
                return;
            }else index = (hashcode(key) + i * hashcode2(key)) % max;
        }

        array[index].flag = 1;
        array[index].data = new_item;
        size++;

        printf("\n Key (%d) has been inserted \n", key);
    }
}

void remove_element(int key)
{
    int index = hashcode(key);
    int i = index;

    /* probing through array until we reach an empty space
    where not even once an element had been present */
    while (array[i].flag != 0)
    {
        if (array[i].flag == 1 && array[i].data->key == key)
        {
            // case when data key matches the given key
            array[i].flag = 2;
            array[i].data = NULL;
            size--;
            printf("\n Key (%d) has been removed \n", key);
            return;
        }
        i = (i + 1) % max;
        if (i == index)
        {
            break;
        }
    }

    printf("\n This key does not exist \n");
}

/* to display all the elements of hash table */
void display()
{
    int i;
    for (i = 0; i < max; i++)
    {
        struct item *current = (struct item *)array[i].data;
        if (current == NULL)
        {
            printf("\n Array[%d] has no elements \n", i);
        }
        else
        {
            printf("\n Array[%d] has elements -: \n %d(key) and %d(value) ", i, current->key, current->value);
        }
    }
}

int main()
{
    system("cls");
    int choice, key, value, n, c;

    array = (struct hashtable_item *)malloc(max * sizeof(struct hashtable_item));

    init_array();

    do
    {
        printf("Implementation of Hash Table in C with Double Hashing \n\n");

        printf("MENU-: \n1.Inserting item in the Hashtable"
               "\n2.Removing item from the Hashtable"
               "\n3.Check the size of Hashtable"
               "\n4.Display Hashtable"
               "\n\n Please enter your choice-:");

        scanf("%d", &choice);

        switch (choice)

        {
        case 1:
            printf("Inserting element in Hashtable\n");
            printf("Enter key-:\t");
            scanf("%d", &key);
            printf("Enter value-:\t");
            scanf("%d", &value);
            insert(key, value);

            break;

        case 2:
            printf("Deleting in Hashtable \n Enter the key to delete-:");
            scanf("%d", &key);
            remove_element(key);

            break;

        case 3:
            n = size_of_hashtable();
            printf("Size of Hashtable is-:%d\n", n);

            break;
        case 4:
            display();
            break;
        default:
            printf("Wrong Input\n");
        }

        printf("\n Do you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    } while (c == 1);

    getchar();
    return 0;
}