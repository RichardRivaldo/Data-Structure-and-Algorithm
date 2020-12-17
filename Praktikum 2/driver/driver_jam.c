/*
Richard Rivaldo / 13519185
Pra-Praktikum 2 02/09/2020

File driver_jam.c
Driver dari ADT Jam */

#include <stdio.h>
#include "jam.c"

int main(){

    /* KAMUS LOKAL */
    JAM jam1, jam2;

    /* ALGORITMA */

    /* Menginput jam */
    BacaJAM(&jam1);

    /* Menampilkan jam yang telah diinput */
    printf("Jam yang telah diinput: ");
    TulisJAM(jam1);
    printf("\n");

    /* Mengonversi dari sebuah jam ke detik */
    printf("Konversi jam tersebut ke dalam detik: %ld\n", JAMToDetik(jam1));

    /* Mengonversi dari detik ke jam */
    printf("Konversi 6000 detik ke dalam jam: ");
    jam2 = DetikToJAM(6000);
    /* Menampilkan jam yang telah dikonversi dari detik */
    TulisJAM(jam2); printf("\n");

    if(JEQ(jam1, jam2)){
        printf("Jam1 sama dengan Jam2.\n");
    }

    if(JNEQ(jam1, jam2)){
        printf("Jam1 tidak sama dengan Jam2.\n");
    }

    if(JLT(jam1, jam2)){
        printf("Jam1 lebih kecil dari Jam2.\n");
    }

    if(JGT(jam1, jam2)){
        printf("Jam1 lebih besar dari Jam2.\n");
    }

    printf("NextDetik dari Jam1 adalah: "); TulisJAM(NextDetik(jam1)); printf("\n");
    printf("Next10Detik dari Jam1 adalah: "); TulisJAM(NextNDetik(jam1, 10)); printf("\n");
    printf("PrevDetik dari Jam2 adalah: "); TulisJAM(PrevDetik(jam2)); printf("\n");
    printf("Prev10Detik dari Jam2 adalah: "); TulisJAM(PrevNDetik(jam2, 10)); printf("\n");
    printf("Durasi dari Jam1 ke Jam2 adalah: %ld\n", Durasi(jam1, jam2));

    return 0;
}
