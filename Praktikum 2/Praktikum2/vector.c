/*
Richard Rivaldo / 13519185
Praktikum 2 03/09/2020

File vector.c
Body dari vector.h */

#include <stdio.h>
#include <math.h>
#include "vector.h"


VECTOR MakeVector(float x, float y){
    /* Membentuk sebuah VECTOR dengan komponen absis x dan komponen ordinat y */
    VECTOR vectorbaru;

    AbsisComponent(vectorbaru) = x;
    OrdinatComponent(vectorbaru) = y;

    return vectorbaru;
}


void TulisVector(VECTOR v){
    /* Nilai v ditulis ke layar dengan format "<X,Y>"
    tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
    Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. v terdefinisi */
    /* F.S. v tertulis di layar dengan format "<X,Y>" */

    printf("<%f,%f>", AbsisComponent(v), OrdinatComponent(y));

}


float Magnitude(VECTOR v){
    /* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */

    return(sqrt(AbsisComponent(v) * AbsisComponent(v) + OrdinatComponent(v) * OrdinatComponent(v));
}


VECTOR Add(VECTOR a, VECTOR b){
    /* Menghasilkan sebuah vector yang merupakan hasil a + b.
    Komponen absis vector hasil adalah vector pertama
    ditambah vector kedua, begitu pula dengan ordinatnya */

    VECTOR hasil;

    AbsisComponent(hasil) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(hasil) = OrdinatComponent(a) + OrdinatComponent(b);

    return hasil;
}


VECTOR Substract(VECTOR a, VECTOR b){
    /* Menghasilkan sebuah vector yang merupakan hasil a - b.
       Komponen absis vector hasil adalah vector pertama
       dikurangi vector kedua, begitu pula dengan ordinatnya */

    VECTOR hasil;

    AbsisComponent(hasil) = AbsisComponent(a) - AbsisComponent(b);
    OrdinatComponent(hasil) = OrdinatComponent(a) - OrdinatComponent(b);

    return hasil;
}


float Dot(VECTOR a, VECTOR b){
    /* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */

    return((AbsisComponent(a) * AbsisComponent(b) + OrdinatComponent(a) * OrdinatComponent(b)));
}


VECTOR Multiply(VECTOR v, float s){
    /* Menghasilkan perkalian skalar vector dengan s, yakni
    (s * a.x, s * a.y) */

    VECTOR hasil;

    AbsisComponent(hasil) = AbsisComponent(v) * s;
    OrdinatComponent(hasil) = OrdinatComponent(v) * s;

    return hasil;
}
