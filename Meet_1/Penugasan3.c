#include<stdio.h>

int umur, ans, tmpCandle, tmpMax;

int main(){
    
    printf("Umur ulang tahun: ");
    scanf("%d", &umur);
    tmpMax = 0;

    printf("Input tinggi setiap lilin: ");
    for(int i = 0; i<umur; i++){
        scanf("%d", &tmpCandle);
        
        if(tmpCandle>tmpMax){
            tmpMax = tmpCandle;
            ans = 1;
        }
        
        else if(tmpCandle==tmpMax){
            ans++;
        }
    }

    printf("Jumlah lilin yang dapat dipadamkan: %d", ans);

    return 0;
}