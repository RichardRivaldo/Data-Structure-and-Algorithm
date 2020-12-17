/*
Richard Rivaldo / 13519185
Pra-Praktikum 2 02/09/2020

File point.c
Body / Realisasi Fungsi dan Prosedur ADT Point */

#include <stdio.h>
#include <math.h>
#include "point.h"

POINT MakePOINT (float X, float Y){
    /* *** Konstruktor membentuk POINT *** */
    /* Membentuk sebuah POINT dari komponen-komponennya */

    /* KAMUS LOKAL */
    POINT P1;

    /* ALGORITMA */
    Absis(P1) = X;
    Ordinat(P1) = Y;

    return P1;
}


void BacaPOINT (POINT *P){
    /* Membaca nilai absis dan ordinat dari keyboard dan membentuk
       POINT P berdasarkan dari nilai absis dan ordinat tersebut */
    /* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
    /* Contoh: 1 2
       akan membentuk POINT <1,2> */
    /* I.S. Sembarang */
    /* F.S. P terdefinisi */

    /* KAMUS LOKAL */
    float X, Y;

    scanf("%f %f", &X, &Y);

    *P = MakePOINT(X,Y);
}


void TulisPOINT (POINT P){
    /* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. P terdefinisi */
    /* F.S. P tertulis di layar dengan format "(X,Y)" */

    /* *** Kelompok operasi relasional terhadap POINT *** */

    /* KAMUS LOKAL */

    /* ALGORIMTA */
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}


boolean EQ (POINT P1, POINT P2){
    /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    return ((Absis(P1) == (Absis(P2)) && (Ordinat(P1) == Ordinat(P2))));
}


boolean NEQ (POINT P1, POINT P2){
    /* Mengirimkan true jika P1 tidak sama dengan P2 */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    return (!EQ(P1, P2));
}


boolean IsOnSbX (POINT P){
    /* Menghasilkan true jika P terletak Pada sumbu X */

    /* KAMUS LOKAL */

    /* ALGORITMMA */

    return (Ordinat(P) == 0);
}


boolean IsOnSbY (POINT P){
    /* Menghasilkan true jika P terletak pada sumbu Y */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    return (Absis(P) == 0);
}


boolean IsOrigin (POINT P){
    /* Menghasilkan true jika P adalah titik origin */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    return (IsOnSbX(P) && IsOnSbY(P));
}


int Kuadran (POINT P){
    /* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
    /* Prekondisi : P bukan titik origin, */
    /*              dan P tidak terletak di salah satu sumbu */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    if ((Absis(P) > 0) && (Ordinat(P) > 0)){
        return 1;
        }
    else if((Absis(P) < 0) && (Ordinat(P) > 0)){
        return 2;
    }
    else if ((Absis(P) > 0) && (Ordinat(P) < 0)){
        return 4;
    }
    else if ((Absis(P) < 0) && (Ordinat(P) < 0)){
        return 3;
    }
    else{
        return -1;
    }
}


POINT NextX (POINT P){
    /* Mengirim salinan P dengan absis ditambah satu */

    /* KAMUS LOKAL  */

    /* ALGORITMA */

    Absis(P) = Absis(P) + 1;
    return P;
}


POINT NextY (POINT P){
    /* Mengirim salinan P dengan ordinat ditambah satu */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    Ordinat(P) = Ordinat(P) + 1;
    return P;
}


POINT PlusDelta (POINT P, float deltaX, float deltaY){
    /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;

    return P;
}


POINT MirrorOf (POINT P, boolean SbX){
    /* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
    /* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
    /* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    if(SbX){
        Ordinat(P) = 0 - Ordinat(P);
    }
    else{
        Absis(P) = 0 - Absis(P);
    }
    return P;
}


float Jarak0 (POINT P){
    /* Menghitung jarak P ke (0,0) */

    /* KAMUS LOKAL */

    float jarak;

    /* ALGORITMA */

    jarak = sqrt((Absis(P) * Absis(P)) + (Ordinat(P) * Ordinat(P)));
    return jarak;
}


float Panjang (POINT P1, POINT P2){
    /* Menghitung jarak dari P2 ke P1 yang juga merupakan panjang dari garis yang dibentuk */

    /* KAMUS LOKAL */

    float jarak;

    /* ALGORITMA */

    jarak = sqrt((Absis(P2) - Absis(P1)) * ((Absis(P2) - Absis(P1)) + ((Ordinat(P2) - Ordinat(P1))) * ((Ordinat(P2) - Ordinat(P1)))));

    return jarak;
}


void Geser (POINT *P, float deltaX, float deltaY){
    /* I.S. P terdefinisi */
    /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}


void GeserKeSbX (POINT *P){
    /* I.S. P terdefinisi */
    /* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
    /* Proses : P digeser ke sumbu X. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
    /* I.S. P terdefinisi*/
    /* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
    /* Proses : P digeser ke sumbu Y. */
    /* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */

    /* KAMUS LOKAL */

    /*ALGORITMA */

    Absis(*P) = 0;
}


void Mirror (POINT *P, boolean SbX){
    /* I.S. P terdefinisi */
    /* F.S. P dicerminkan tergantung nilai SbX atau SbY */
    /* Jika SbX true maka dicerminkan terhadap sumbu X */
    /* Jika SbX false maka dicerminkan terhadap sumbu Y */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    if(SbX){
        Ordinat(*P) = 0 - Ordinat(*P);
    }
    else{
        Absis(*P) = 0 - Absis(*P);
    }
}

void Putar (POINT *P, float Sudut){
    /* I.S. P terdefinisi */
    /* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/

    /* KAMUS LOKAL */

    const float radSudut = -((Sudut/180) * acos(-1));

    /* ALGORITMA */

    Absis(*P) = Absis(*P)*cos(radSudut) - Ordinat(*P)*sin(radSudut);
    Ordinat(*P) = Ordinat(*P)*cos(radSudut) + Absis(*P)*sin(radSudut);
}
