/* Richard Rivaldo 13519185
Praktikum 5 Matriks */

#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>

void TulisNilaiX(MATRIKS M, indeks j, ElType X){
    int i;
    boolean plusKoma = false;
    printf("[");
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        if(Elmt(M, i, j) ==  X){
            if(plusKoma){
                printf(",%d", i);
            }
            else{
                printf("%d", i);
                plusKoma = true;
            }
        }
    }
    printf("]");
}

void TulisStatistikMhs(MATRIKS M, indeks i){
    ElType max, min;

    MaxMinBrs(M, i, &max, &min);

    printf("[%d] %.2f %d %d\n", i, RataBrs(M, i), max, min);
}

void TulisStatistikMK (MATRIKS M, indeks j){
    ElType max, min;
    int totalMax, totalMin;

    MaxMinKol(M, j, &max, &min);
    float avg = RataKol(M, j);
    totalMax = CountXKol(M, j, max);
    totalMin = CountXKol(M, j, min);

    printf("[%d] %.2f [%d %d ", j, avg, max, totalMax);
    TulisNilaiX(M, j, max);
    printf("] [%d %d ", min, totalMin);
    TulisNilaiX(M, j, min);
    printf("]\n");
}

int main(){
    int i, j, baris, kolom;
    MATRIKS MNilai;

    scanf("%d", &baris);
    scanf("%d", &kolom);

    BacaMATRIKS(&MNilai, baris, kolom);

    printf("STATISTIK PER MAHASISWA\n");
    for(i = GetFirstIdxBrs(MNilai); i <= GetLastIdxBrs(MNilai); i++){
        TulisStatistikMhs(MNilai, i);
    }
    printf("STATISTIK PER MATA KULIAH\n");
    for(j = GetFirstIdxKol(MNilai); j <= GetLastIdxKol(MNilai); j++){
        TulisStatistikMK(MNilai, j);
    }
    return 0;
}
