/* Richard Rivaldo - 13519185
Pra-Praktikum 10 - List Double Pointer */

#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty (List L){
    /* Mengirim true jika list kosong. Lihat definisi di atas. */
    return((First(L) == Nil) && (Last(L) == Nil));
}

void CreateEmpty (List *L){
    /* I.S. L sembarang  */
    /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Nil;
    Last(*L) = Nil;
}

address Alokasi (infotype X){
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil. */
    /* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil. */
    ElmtList *P = (ElmtList*) malloc(sizeof(ElmtList));

    if(P != Nil){
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
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
    /* Mencari apakah ada elemen list dengan Info(P)=X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    address PFound = Nil;
    boolean Found = false;
    if(!IsEmpty(L)){
        while((P != Nil) && !(Found)){
            if(Info(P) == X){
                PFound = P;
                Found = true;
            }
            else{
                P = Next(P);
            }
        }
    }
    return PFound;
}

void InsVFirst (List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X);
    Next(P) = First(*L); Prev(P) = Nil;
    if(P != Nil){
        if(!(IsEmpty(*L))){
            Prev(First(*L)) = P;
        }
        else{
            Last(*L) = P;
        }
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

    address(P) = Alokasi(X);
    Next(P) = Nil; Prev(P) = Last(*L);

    if(P != Nil){
        if(!(IsEmpty(*L))){
            Next(Last(*L)) = P;
        }
        else{
            First(*L) = P;
        }
        Last(*L) = P;
    }
}

void DelVFirst (List *L, infotype *X){
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X){
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
    Next(P) = First(*L);
    if(IsEmpty(*L)){
        Last(*L) = P;
    }
    else{
        Prev(First(*L)) = P;
    }
    First(*L) = P;
}

void InsertLast (List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    Prev(P) = Last(*L);
    if(!(IsEmpty(*L))){
        Next(Last(*L)) = P;
    }
    else{
        First(*L) = P;
    }
    Last(*L) = P;
}


void InsertAfter (List *L, address P, address Prec){
    /* I.S. Prec pastilah elemen list; P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    if(Next(Prec) == Nil){
        Last(*L) = P;
    }
    else{
        Prev(Next(Prec)) = P;
    }

    Next(Prec) = P;
    Prev(P) = Prec;
}

void InsertBefore (List *L, address P, address Succ){
    /* I.S. Succ pastilah elemen list; P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    Prev(P) = Prev(Succ);
    if(Prev(Succ) == Nil){
        First(*L) = P;
    }
    else{
        Next(Prev(Succ)) = P;
    }
    Prev(Succ) = P;
    Next(P) = Succ;
}

void DelFirst (List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    First(*L) = Next(First(*L));
    if(First(*L) == Nil){
        Last(*L) = Nil;
    }
    else{
        Prev(First(*L)) = Nil;
    }
}

void DelLast (List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    *P = Last(*L);
    Last(*L) = Prev(Last(*L));
    if(Last(*L) == Nil){
        First(*L) = Nil;
    }
    else{
        Next(Last(*L)) = Nil;
    }
}

void DelP (List *L, infotype X){
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
    /* maka P dihapus dari list dan didealokasi */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */
    address P = Search(*L, X);

    if(P != Nil){
        if(Next(P) != Nil){
            DelBefore(L, P, Next(P));
        }
        else if(Prev(P) != Nil){
            DelAfter(L, P, Prev(P));
        }
        else{
            CreateEmpty(L);
        }
        Dealokasi(P);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    /* I.S. List tidak kosong. Prec adalah anggota list. */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);

    Next(Prec) = Next(*Pdel);
    if(Next(*Pdel) != Nil){
        Prev(Next(*Pdel)) = Prec;
    }
    else{
        Last(*L) = Prec;
    }
    Next(*Pdel) = Nil; Prev(*Pdel) = Nil;
}

void DelBefore (List *L, address *Pdel, address Succ){
    /* I.S. List tidak kosong. Succ adalah anggota list. */
    /* F.S. Menghapus Prev(Succ): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Prev(Succ);

    Prev(Succ) = Prev(*Pdel);

    if(Prev(*Pdel) != Nil){
        Next(Prev(*Pdel)) = Succ;
    }
    else{
        First(*L) = Succ;
    }

    Prev(*Pdel) = Nil; Next(*Pdel) = Nil;
}

void PrintForward (List L){
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
    /* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P = First(L);

    printf("[");
    if(!IsEmpty(L)){
        while(P != Nil){
            printf("%d", Info(P));
            P = Next(P);

            if(P != Nil){
                printf(",");
            }
        }
    }
    printf("]");
}

void PrintBackward (List L){
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
    /* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P = Last(L);

    printf("[");
    if(!IsEmpty(L)){
        while(P != Nil){
            printf("%d", Info(P));
            P = Prev(P);

            if(P != Nil){
                printf(",");
            }
        }
    }
    printf("]");
}
