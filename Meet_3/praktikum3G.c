#include <stdio.h>
#define ROW 2
#define COL 3
int i, j;
int main(void) {
	int Matriks_A[ROW][COL]={{4,2,3},{5,7,6}};
	int Matriks_B[ROW][COL]={{1,8,9},{3,5,4}};
	int Matriks_C[ROW][COL];
	/*
	
	4 2 3     1 8 9     5 10 12
	5 7 6     3 5 4     8 12 10
	*/
	printf("Matriks_C adalah : \n");
	for( i = 0; i < ROW; i++){
		
		for( j = 0; j < COL; j++) {
			Matriks_C[i][j] = Matriks_A[i][j]+ Matriks_B[i][j];
		}
		
		printf("%d %d %d\n", Matriks_C[i][0], Matriks_C[i][1], Matriks_C[i][2]);
	}
	return 0;
}
