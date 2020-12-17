/* Richard Rivaldo 13519185
Pra-Praktikum 9 - ADT List Linier */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty (List L){
    /* Mengirim true jika list kosong */
    return(First(L) == Nil);
}

void CreateEmpty (List *L){
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
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
    return(P);
}

void Dealokasi (address *P){
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    free(*P);
}

address Search (List L, infotype X){
    /* Mencari apakah ada elemen list dengan Info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */
    address P = First(L);
    address PFound = Nil;
    boolean found = false;
    while((P != Nil) && (!found)){
        if(Info(P) == X){
            found = true;
            PFound = P;
        }
        else{
            P = Next(P);
        }
    }
    return(PFound);
}

void InsVFirst (List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X);
    if(P != Nil){
        if(IsEmpty(*L)){
            First(*L) = P;
        }
        else{
            Next(P) = First(*L);
            First(*L) = P;
        }
    }
}

void InsVLast (List *L, infotype X){
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if(IsEmpty(*L)){
        InsVFirst(L, X);
    }
    else{
        address P = Alokasi(X);
        if(P != Nil){
            address temp = First(*L);
            while(Next(temp) != Nil){
                temp = Next(temp);
            }
            InsertAfter(L, P, temp);
        }
    }
}

void DelVFirst (List *L, infotype *X){
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */
    address P = First(*L), Prec = Nil;
    while(Next(P) != Nil){
        Prec = P;
        P = Next(P);
    }
    if(Prec == Nil){
        First(*L)= Nil;
    }
    else{
        Next(Prec) = Nil;
    }
    *X = Info(P);
    Dealokasi(&P);
}

void InsertFirst (List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if(IsEmpty(*L)){
        First(*L) = P;
    }
    else{
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P){
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if(IsEmpty(*L)){
        InsertFirst(L, P);
    }
    else{
        address Prec = First(*L);
        while(Next(Prec) != Nil){
            Prec = Next(Prec);
        }
        InsertAfter(L, P, Prec);
    }
}

void DelFirst (List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    First(*L) = Next(First(*L));
}

void DelP (List *L, infotype X){
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
    /* Maka P dihapus dari list dan di-dealokasi */
    /* Jika ada lebih dari satu elemen list dengan Info bernilai X */
    /* maka yang dihapus hanya elemen pertama dengan Info = X */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */
    if(!IsEmpty(*L)){
        if(Info(First(*L)) == X){
            address P;
            DelFirst(L, &P);
        }
        else{
            address temp = First(*L), Prec = Nil;
            boolean found;

            while((temp != Nil) && (!found)){
                if(Info(temp) == X){
                    found = true;
                }
                else{
                    Prec = temp;
                    temp = Next(temp);
                }
            }
            if(found){
                address Q;
                DelAfter(L, &Q, Prec);
                Dealokasi(&temp);
            }
        }
    }
}

void DelLast (List *L, address *P){
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen terakhir yg lama, */
    /* jika ada */
    address temp = First(*L), Prec = Nil;

    while(Next(temp) != Nil){
        Prec = temp;
        temp = Next(temp);
    }
    if(Prec == Nil){
        First(*L) = Nil;
    }
    else{
        Next(Prec) = Nil;
    }
    *P = temp;
}

void DelAfter (List *L, address *Pdel, address Prec){
    /* I.S. List tidak kosong. Prec adalah anggota list  */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    address temp = Next(Prec);
    *Pdel = temp;
    Next(Prec)= Next(temp);
    Next(temp) = Nil;
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

int NbElmt (List L){
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    if(IsEmpty(L)){
        return 0;
    }
    else{
        int n = 0;
        address P = First(L);

        while(P != Nil){
            n++;
            P = Next(P);
        }
        return n;
    }
}

infotype Min (List L){
    /* Mengirimkan nilai Info(P) yang minimum */
    infotype min = Info(First(L));
    address P = First(L);

    while(P != Nil){
        if(Info(P) < min){
            min = Info(P);
        }
        else{
            P = Next(P);
        }
    }
    return min;
}

infotype Max (List L){
    /* Mengirimkan nilai Info(P) yang maksimum */
    infotype max = Info(First(L));
    address P = First(L);

    while(P != Nil){
        if(Info(P) > max){
            max = Info(P);
        }
        else{
            P = Next(P);
        }
    }
    return max;
}

void Konkat1 (List *L1, List *L2, List *L3){
    /* I.S. L1 dan L2 sembarang */
    /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
    /* Konkatenasi dua buah list : L1 dan L2    */
    /* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
    /* dan L1 serta L2 menjadi list kosong.*/
    /* Tidak ada alokasi/dealokasi pada prosedur ini */
    CreateEmpty(L3);

    if(IsEmpty(*L1)){
        First(*L3) = First(*L2);
    }
    else{
        First(*L3) = First(*L1);

        address P = First(*L1);

        while(Next(P) != Nil){
            P = Next(P);
        }
        Next(P) = First(*L2);
    }

    CreateEmpty(L1);
    CreateEmpty(L2);
}
