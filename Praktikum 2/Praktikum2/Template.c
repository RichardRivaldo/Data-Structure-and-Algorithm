/*
Richard Rivaldo / 13519185
Praktikum 2 03/09/2020

File mjam.c */

#include <stdio.h>
#include "jam.c"

int main(){

    int jumlahRecord;
    int indeks = 1;
    int H1, M1, S1;
    int H2, M2, S2;
    JAM Jam1, Jam2;
    JAM *PalingAwal, *PalingAkhir, tempJamAwal, tempJamAkhir;

    scanf("%d\n", &jumlahRecord);

    while(indeks <= jumlahRecord){
        printf("[%d]", &indeks);
        BacaJAM(&Jam1);
        BacaJAM(&Jam2);
        printf("%ld\n", Durasi(Jam1, Jam2));

        *PalingAwal = Jam1;
        tempJamAwal = Jam1;
        *PalingAkhir = Jam2;
        tempJamAkhir = Jam2;
        if (JLT(tempJamAwal, *PalingAwal)){
            *PalingAwal = tempJamAwal;
        }
        if (JLT(*PalingAkhir, tempJamAkhir)){
            *PalingAkhir = tempJamAkhir;
        }
        indeks += 1;
    }

    TulisJAM(*PalingAwal); printf("\n");
    TulisJAM(*PalingAkhir); printf("\n");

    return 0;
}
