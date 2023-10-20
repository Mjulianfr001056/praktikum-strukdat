#include<stdio.h>

double nilaiKuis, nilaiUTS, nilaiUAS;
char NIM[20], nama[20];

int main(){
    printf("Masukkan NIM: ");
    scanf("%s", NIM);

    printf("Masukkan nama: ");
    fflush(stdin);
    gets(nama);

    printf("Masukkan nilai kuis: ");
    scanf("%lf", &nilaiKuis);

    printf("Masukkan nilai UTS: ");
    scanf("%lf", &nilaiUTS);

    printf("Masukkan nilai UAS: ");
    scanf("%lf", &nilaiUAS);


    printf("\nData Mahasiswa \n");    
    printf("NIM: %s. \n", NIM);    
    printf("Nama: %s. \n", nama);    
    printf("Nilai kuis: %.2lf. \n", nilaiKuis);
    printf("Nilai UTS: %.2lf. \n", nilaiUTS);
    printf("Nilai UAS: %.2lf. \n", nilaiUAS);
    
    printf("Nilai akhir: %.2lf.", 0.2 * nilaiKuis + 0.3 * nilaiUTS + 0.5 * nilaiUAS);

    return 0;
}