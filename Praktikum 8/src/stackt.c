/* Richard Rivaldo/13519185
Pra-Praktikum 8 - Stack */

#include "stackt.h"
#include <stdio.h>

void CreateEmpty (Stack *S){
    /* I.S. sembarang; */
    /* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
    /* jadi indeksnya antara 0.. MaxEl */
    /* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}

boolean IsEmpty (Stack S){
    /* Mengirim true jika Stack kosong: lihat definisi di atas */
    return(Top(S) == Nil);
}

boolean IsFull (Stack S){
    /* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return(Top(S) == (MaxEl - 1));
}

void Push (Stack * S, infotype X){
    /* Menambahkan X sebagai elemen Stack S. */
    /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
    /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    if(IsEmpty(*S)){
        Top(*S) = 0;
    }
    else{
        Top(*S) += 1;
    }
    InfoTop(*S) = X;
}

void Pop (Stack * S, infotype* X){
    /* Menghapus X dari Stack S. */
    /* I.S. S  tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    if(Top(*S) == 0){
        Top(*S) = Nil;
    }
    else{
        Top(*S) -= 1;
    }
}
