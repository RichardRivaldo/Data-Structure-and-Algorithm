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

boolean FSearch (List L, address P){
    /* Mencari apakah ada elemen list yang beralamat P */
    /* Mengirimkan true jika ada, false jika tidak ada */
    address P1 = First(L);
    boolean found = false;

    if(!IsEmpty(L)){
        while((P1 != Nil) && (!found)){
            if(P1 == P){
                found = true;
            }
            else{
                P1 = Next(P1);
            }
        }
    }
    return found;
}

address SearchPrec (List L, infotype X){
    /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
    /* Mencari apakah ada elemen list dengan Info(P)=X */
    /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
    /* Jika tidak ada, mengirimkan Nil */
    /* Jika P adalah elemen pertama, maka Prec=Nil */
    /* Search dengan spesifikasi seperti ini menghindari */
    /* traversal ulang jika setelah Search akan dilakukan operasi lain */
    address Prec = Nil, P = First(L), Hasil = Nil;
    boolean found = false;

    if(!IsEmpty(L)){
        while((P != Nil) && (!found)){
            if(Info(P) == X){
                Hasil = Prec;
                found = true;
            }
            else{
                Prec = P;
                P = Next(P);
            }
        }
    }
    return Hasil;
}

address AdrMax (List L){
    /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    address max = First(L), P = First(L);
    while(P != Nil){
        if(Info(P) > Info(max)){
            max = P;
        }
        P = Next(P);
    }
    return max;
}

address AdrMin (List L){
    /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    address min = First(L), P = First(L);
    while(P != Nil){
        if(Info(P) < Info(min)){
            min = P;
        }
        P = Next(P);
    }
    return min;
}

float Average (List L){
    /* Mengirimkan nilai rata-rata info(P) */
    int sum = 0, count = 0;
    address P = First(L);
    while(P != Nil){
        count++;
        sum += Info(P);
        P = Next(P);
    }
    float avg = sum/count;
    return(avg);
}

void DelAll (List *L){
    /* Delete semua elemen list dan alamat elemen di-dealokasi */
    infotype elmt;
    while(!IsEmpty(*L)){
        DelVFirst(L, &elmt);
    }
    CreateEmpty(L);
}

void InversList (List *L){
    /* I.S. sembarang. */
    /* F.S. elemen list dibalik : */
    /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
    /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    address P1 = First(*L), P2 = Next(P1), temp = First(*L);
    while(P2 != Nil){
        P1 = P2;
        P2 = Next(P2);
        InsertFirst(L, P1);
        Next(temp) = P2;
    }
}

List FInversList (List L){
    /* Mengirimkan list baru, hasil invers dari L */
    /* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
    /* Jika alokasi gagal, hasilnya list kosong */
    /* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
    infotype tempInfo;
    address tempAddress;

    List temp;
    CreateEmpty(&temp);
    temp = FCopyList(L);

    List Hasil;
    CreateEmpty(&Hasil);

    while(!IsEmpty(temp)){
        DelVFirst(&temp, &tempInfo);
        tempAddress = Alokasi(tempInfo);

        if(tempAddress != Nil){
            InsertFirst(&Hasil, tempAddress);
        }
        else{
            DelAll(&Hasil);
            return Hasil;
        }
    }
    return Hasil;
}

void CopyList (List *L1, List *L2){
    /* I.S. L1 sembarang. F.S. L2=L1 */
    /* L1 dan L2 "menunjuk" kepada list yang sama.*/
    /* Tidak ada alokasi/dealokasi elemen */
    First(*L2) = First(*L1);
}

List FCopyList (List L){
    /* Mengirimkan list yang merupakan salinan L */
    /* dengan melakukan alokasi. */
    /* Jika ada alokasi gagal, hasilnya list kosong dan */
    /* semua elemen yang terlanjur di-alokasi, harus didealokasi */
    address P = First(L), tempAddress;

    List Hasil;
    CreateEmpty(&Hasil);

    while(P != Nil){
        tempAddress = Alokasi(Info(P));
        if(tempAddress != Nil){
            InsertLast(&Hasil, tempAddress);
            P = Next(P);
        }
        else{
            DelAll(&Hasil);
            return Hasil;
        }
    }
    return Hasil;
}

void CpAlokList (List Lin, List *Lout){
    /* I.S. Lin sembarang. */
    /* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
    /* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
    /* dengan melakukan alokasi elemen. */
    /* Lout adalah list kosong jika ada alokasi elemen yang gagal */
    CreateEmpty(Lout);
    *Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3){
    /* I.S. L1 dan L2 sembarang */
    /* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
    /* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
    /* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
    /* harus di-dealokasi dan L3=Nil*/
    /* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
    /* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
    /* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
    /* dan semua elemen yang pernah dialokasi didealokasi */
    address P, tempAddress;
    infotype tempInfo;
    boolean fail = false;

    CreateEmpty(L3);

    if(!IsEmpty(L1)){
        P = First(L1);
        while((P != Nil) && (!fail)){
            tempInfo = Info(P);
            tempAddress = Alokasi(tempInfo);
            if(tempAddress != Nil){
                InsertLast(L3, tempAddress);
                P = Next(P);
            }
            else{
                DelAll(L3);
                fail = true;
            }
        }
        P = First(L2);
        while((P != Nil) && (!fail)){
            tempInfo = Info(P);
            tempAddress = Alokasi(tempInfo);
            if(tempAddress != Nil){
                InsertLast(L3, tempAddress);
                P = Next(P);
            }
            else{
                DelAll(L3);
                fail = true;
            }
        }
    }
    else{
        P = First(L2);
        while((P != Nil) && (!fail)){
            tempInfo = Info(P);
            tempAddress = Alokasi(tempInfo);
            if(tempAddress != Nil){
                InsertLast(L3, tempAddress);
                P = Next(P);
            }
            else{
                DelAll(L3);
                fail = true;
            }
        }
    }
}

void PecahList (List *L1, List *L2, List L){
    /* I.S. L mungkin kosong */
    /* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
    /* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
    /* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
    /* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
    int n1 = NbElmt(L) / 2, n2 = NbElmt(L) - n1;

    CreateEmpty(L1); CreateEmpty(L2);

    infotype tempInfo;
    address P = First(L), tempAddress;

    while(n1 > 0){
        tempInfo = Info(P);
        tempAddress = Alokasi(tempInfo);

        if(tempAddress != Nil){
            InsertLast(L1, tempAddress);
            P = Next(P);
            n1--;
        }
    }
    while(n2 > 0){
        tempInfo = Info(P);
        tempAddress = Alokasi(tempInfo);

        if(tempAddress != Nil){
            InsertLast(L2, tempAddress);
            P = Next(P);
            n2--;
        }
    }
}
