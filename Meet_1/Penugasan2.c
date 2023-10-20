#include<stdio.h>

double p, l;

double hitungLuas(int p, int l){
    return p * l;
}

double hitungKeliling(int p, int l){
    return 2*(p+l);
}

int main (){
    printf("Masukkan panjang: ");
    scanf("%lf", &p);

    printf("Masukkan lebar: ");
    scanf("%lf", &l);

    double luas = hitungLuas(p, l);
    double keliling = hitungKeliling(p, l);

    printf("Luas persegi: %.2lf  \n", luas);
    printf("Keliling persegi: %.2lf", keliling);

    return 0;
}