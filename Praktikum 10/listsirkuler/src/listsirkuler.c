/* Richard Rivaldo - 13519185
Pra-Praktikum 10 - List Sirkuler */

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty (List L){
    /* Mengirim true jika list kosong. Lihat definisi di atas. */
    return(First(L) == Nil);

}

void CreateEmpty (List *L){
    /* I.S. L sembarang             */
    /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Nil;
}

address Alokasi (infotype X){
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    ElmtList *P = (ElmtList*) malloc(sizeof(ElmtList));

    if(P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address P){
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    free(P);
}

address Search (List L, infotype X){
    /* Mencari apakah ada elemen list dengan Info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    if(!IsEmpty(L)){
        while((Next(P) != First(L)) && (Info(P) != X)){
            P = Next(P);
        }
        if(Info(P) == X){
            return P;
        }
        else{
            return Nil;
        }
    }
    else{
        return Nil;
    }
}

void InsVFirst (List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X);

    if(P != Nil){
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X);

    if(P != Nil){
        InsertLast(L, P);
    }
}

void DelVFirst (List *L, infotype * X){
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */
    address P;

    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

void DelVLast (List *L, infotype * X){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */
    address P;

    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

void InsertFirst (List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    InsertLast(L, P);
    First(*L) = P;
}

void InsertLast (List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if(IsEmpty(*L)){
        First(*L) = P;
        Next(P) = P;
    }
    else{
        address temp = First(*L);
        while(Next(temp) != First(*L)){
            temp = Next(temp);
        }
        InsertAfter(L, P, temp);
    }
}

void InsertAfter (List *L, address P, address Prec){
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void DelFirst (List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */
    address temp;

    *P = First(*L);
    if(First(*L) == Next(First(*L))){
        First(*L) = Nil;
    }
    else{
        temp = First(*L);
        while(Next(temp) != First(*L)){
            temp = Next(temp);
        }
        First(*L) = Next(First(*L));
        Next(temp) = First(*L);
    }
}

void DelLast (List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen pertama yg lama, */
    /* jika ada */
    address temp = First(*L);

    if(Next(temp) != First(*L)){
        while(Next(Next(temp)) != First(*L)){
            temp = Next(temp);
        }
        DelAfter(L, P, temp);
    }
    else{
        *P = First(*L);
        CreateEmpty(L);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    /* I.S. List tidak kosong. Prec adalah anggota list  */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    if(Next(Prec) == First(*L)){
        First(*L) = Next(First(*L));
    }

    if(Next(First(*L)) == First(*L)){
        CreateEmpty(L);
    }
    else{
        *Pdel = Next(Prec);
        Next(Prec) = Next(Next(Prec));
    }
}

void DelP (List *L, infotype X){
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
    /* Maka P dihapus dari list dan di-dealokasi */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */
    address P = Search(*L, X), temp = Nil;

    if(P != Nil){
        if(P != First(*L)){
            temp = First(*L);
            while(Next(temp) != P){
                temp = Next(temp);
            }
            DelAfter(L, &P, temp);
        }
        else{
            DelFirst(L, &P);
        }
        Dealokasi(P);
    }
}

void PrintInfo (List L){
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");

    if(!IsEmpty(L)){
        address P = First(L);
        while(Next(P) != First(L)){
            printf("%d,", Info(P));
            P = Next(P);
        }
        printf("%d",Info(P));
    }
    printf("]");
}
