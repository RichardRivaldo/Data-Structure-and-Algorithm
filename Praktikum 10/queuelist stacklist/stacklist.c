/* Richard Rivaldo 13519185
Praktikum 10 - Variasi List Linier */

#include "stacklist.h"
#include <stdio.h>
#include <stdlib.h>

void Alokasi (address *P, infotype X){
    /* I.S. Sembarang */
    /* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
            Next(P)=Nil */
    /*      P=Nil jika alokasi gagal */
    *P = (address) malloc(sizeof(ElmtStack));

    if(*P != Nil){
        Next(*P) = Nil;
        Info(*P) = X;
    }
}

void Dealokasi (address P){
    /* I.S. P adalah hasil alokasi, P != Nil */
    /* F.S. Alamat P didealokasi, dikembalikan ke sistem */
    free(P);
}

boolean IsEmpty (Stack S){
    /* Mengirim true jika Stack kosong: TOP(S) = Nil */
    return(Top(S) == Nil);
}

void CreateEmpty (Stack * S){
    /* I.S. sembarang */
    /* F.S. Membuat sebuah stack S yang kosong */
    Top(*S) = Nil;
}

void Push (Stack * S, infotype X){
    /* Menambahkan X sebagai elemen Stack S */
    /* I.S. S mungkin kosong, X terdefinisi */
    /* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
    /*      jika tidak, S tetap */
    /* Pada dasarnya adalah operasi Insert First pada list linier */
    address P; Alokasi(&P, X);

    if(P != Nil){
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop (Stack * S, infotype * X){
    /* Menghapus X dari Stack S. */
    /* I.S. S tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, */
    /*      elemen TOP yang lama didealokasi */
    /* Pada dasarnya adalah operasi Delete First pada list linier */
    address TOP = Top(*S);
    if(Next(Top(*S)) != Nil){
        Top(*S) = Next(Top(*S));
    }
    else{
        CreateEmpty(S);
    }
    *X = Info(TOP);
    Dealokasi(TOP);
}
