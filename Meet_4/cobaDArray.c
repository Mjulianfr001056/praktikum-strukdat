#include<stdio.h>
#include <stdbool.h>
#define ds darray->_size
#define dc darray->_capacity
#define da darray->arr

typedef struct DArray_t DArray;

struct DArray_t{
	int* arr;
	unsigned _size, _capacity;
};

void DArray_init(DArray* darray){
	dc = 2u;
	ds = 0u;
	da = (int*) malloc (sizeof(int) * 2) ;
}

bool DArray_bool(DArray* darray){
	return (ds == 0);
}

void DArray_pushBack(DArray* darray){
	if(ds + 1 > dc){
		unsigned it;
		dc *= 2;
		int* newArr = (int*) malloc(sizeof(int) * dc);
		
		for (it = 0; it < ds; ++it) newArr[it] = da[it];
		
		int* oldArray = da;
		
		da = newArr;
		free(oldArray);
	}
	
	da[ds++]= value;
}

void DArray_popBack(DArray* darray){
	if(!DArray_isEmpty(darray)) ds--;
	else return;
}

int DArray_back(DArray* darray){
    if (!DArray_isEmpty(darray))
        return da[ds-1];
    else return 0;
}

int DArray_front(DArray* darray){
    if (!DArray_isEmpty(darray)) return da[0];
    else return 0;
}

void DArray_setA(DArray* darray, int value, unsigned idx){
	if (!DArray_isEmpty(darray)){
		if(idx >= ds){
			
		}
	}
}
int main(){
	
}
