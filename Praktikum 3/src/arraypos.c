/* Richard Rivaldo / 13519185
8 September 2020 / Pra-Praktikum 3  */

#include "arraypos.h"
#include <stdio.h>

void MakeEmpty (TabInt *T){
    /* I.S. T sembarang */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    /* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

    /* KAMUS LOKAL */
    int i = IdxMin;

    /* ALGORITMA */
    for(i; i <= IdxMax; i++){
        Elmt(*T, i) = ValUndef;
    }
}


int NbElmt (TabInt T){
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */

    /* KAMUS LOKAL */
    int i = IdxMin;
    int NElmt = 0;

    /* ALGORITMA */
    for(i; i <= IdxMax; i++){
        if(Elmt(T, i) == ValUndef){
            return NElmt;
        }
        else{
            NElmt += 1;
        }
    }
    return NElmt;
}


int MaxNbEl (TabInt T){
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    /* IdxMax - IdxMin + 1, IdxMin = 0 rata kiri*/
    return IdxMax + 1;
}


IdxType GetFirstIdx (TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return IdxMin;
}

IdxType GetLastIdx (TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return NbElmt(T) - 1;
}


boolean IsIdxValid (TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(i >= IdxMin && i <= IdxMax);
}


boolean IsIdxEff (TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}


boolean IsEmpty (TabInt T){
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(NbElmt(T) == 0);
}


boolean IsFull (TabInt T){
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(GetFirstIdx(T) == IdxMin && GetLastIdx(T) == IdxMax);
}


void BacaIsi (TabInt *T){
    /* I.S. T sembarang */
    /* F.S. Tabel T terdefinisi */
    /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
          IdxMin satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk T kosong */

    /* KAMUS LOKAL */
    int N;
    int i = IdxMin;
    ElType Elmnt;

    /* ALGORITMA */
    scanf("%d", &N);
    while(N < 0 || N > MaxNbEl(*T)){
        scanf("%d", &N);
    }
    MakeEmpty(T);
    if(N > 0){
        for(i; i < N; i++){
            scanf("%d", &Elmnt);
            Elmt(*T, i) = Elmnt;
        }
    }
}


void TulisIsiTab (TabInt T){
    /* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
       antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
       di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. T boleh kosong */
    /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika tabel kosong : menulis [] */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T);

    /* ALGORITMA */
    if (IsEmpty(T)){
        printf("[]");
    }
    else{
        printf("[");
        for(i; i < GetLastIdx(T); i++){
            printf("%d,", Elmt(T, i));
        }
        printf("%d]", Elmt(T, GetLastIdx(T)));
    }
}


TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus){
    /* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T1);
    TabInt T3;

    /* ALGORITMA */
    MakeEmpty(&T3);

    if(IsEmpty(T1)){
        return T1;
    }
    if(IsEmpty(T2)){
        return T2;
    }

    if(plus){
        for(i; i <= GetLastIdx(T1); i++){
            Elmt(T3, i) = Elmt(T1, i) + Elmt(T2, i);
        }
    }
    else{
        for(i; i <= GetLastIdx(T1); i++){
            Elmt(T3, i) = Elmt(T1, i) - Elmt(T2, i);
        }
    }
    return T3;
}


boolean IsEQ (TabInt T1, TabInt T2){
    /* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T1);

    /* ALGORITMA */
    if(NbElmt(T1) != NbElmt(T2)){
        return false;
    }
    for(i; i <= GetLastIdx(T1); i++){
        if(Elmt(T1, i) != (Elmt(T2, i))){
            return false;
        }
    }
    return true;
}


IdxType Search1 (TabInt T, ElType X){
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
    /* Jika tidak ada, mengirimkan IdxUndef */
    /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
    /* Skema Searching yang digunakan bebas */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T);

    /* ALGORITMA */
    if(IsEmpty(T)){
        return IdxUndef;
    }
    else{
        for(i; i <= GetLastIdx(T); i++){
            if(Elmt(T, i) == X){
                return i;
            }
        }
    }
    return IdxUndef;
}


boolean SearchB (TabInt T, ElType X){
    /* Search apakah ada elemen tabel T yang bernilai X */
    /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
    /* Skema searching yang digunakan bebas */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T);

    /* ALGORITMA */
    for(i; i <= GetLastIdx(T); i++){
        if(Elmt(T, i) == X){
            return true;
        }
    }
    return false;
}


void MaxMin (TabInt T, ElType *Max, ElType *Min){
    /* I.S. Tabel T tidak kosong */
    /* F.S. Max berisi nilai maksimum T;
            Min berisi nilai minimum T */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T);

    /* ALGORITMA */
    *Max = Elmt(T, i);
    *Min = Elmt(T, i);
    for(i; i <= GetLastIdx(T); i++){
        if(Elmt(T, i) > *Max){
            *Max = Elmt(T, i);
        }
        if(Elmt(T, i) < *Min){
            *Min = Elmt(T, i);
        }
    }
}


ElType SumTab (TabInt T){
    /* Menghasilkan hasil penjumlahan semua elemen T */
    /* Jika T kosong menghasilkan 0 */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T);
    ElType jumlah = 0;

    /* ALGORITMA */

    if(IsEmpty(T)){
        return jumlah;
    }
    else{
        for(i; i <= GetLastIdx(T); i++){
            jumlah += Elmt(T, i);
        }
    }
    return jumlah;
}


int CountX (TabInt T, ElType X){
    /* Menghasilkan berapa banyak kemunculan X di T */
    /* Jika T kosong menghasilkan 0 */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T);
    int countx = 0;

    /* ALGORITMA */
    if(IsEmpty(T)){
        return countx;
    }
    else{
        for(i; i <= GetLastIdx(T); i++){
            if(Elmt(T, i) == X){
                countx += 1;
            }
        }
    }
    return countx;
}


boolean IsAllGenap (TabInt T){
    /* Menghailkan true jika semua elemen T genap */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T);

    /* ALGORITMA */
    for(i; i <= GetLastIdx(T); i++){
        if(Elmt(T, i) % 2 != 0){
            return false;
        }
    }
    return true;
}


void Sort (TabInt *T, boolean asc){
    /* I.S. T boleh kosong */
    /* F.S. Jika asc = true, T terurut membesar */
    /*      Jika asc = false, T terurut mengecil */
    /* Proses : Mengurutkan T dengan salah satu algoritma sorting,
       algoritma bebas */

    /* KAMUS LOKAL */
    int i, j;
    ElType temp;

    /* ALGORITMA */
    if (asc){
        for(i = 0; i < NbElmt(*T); i++){
            for(j = i + 1; j < NbElmt(*T); j++){
                if(Elmt(*T, i) > Elmt(*T, j)){
                    temp = Elmt(*T, i);
                    Elmt(*T, i) = Elmt(*T, j);
                    Elmt(*T, j) = temp;
                }
            }
        }
    }
    else{
        for(i = 0; i < NbElmt(*T); i++){
            for(j = i + 1; j < NbElmt(*T); j++){
                if(Elmt(*T, i) < Elmt(*T, j)){
                    temp = Elmt(*T, i);
                    Elmt(*T, i) = Elmt(*T, j);
                    Elmt(*T, j) = temp;
                }
            }
        }
    }
}


void AddAsLastEl (TabInt *T, ElType X){
    /* Proses: Menambahkan X sebagai elemen terakhir tabel */
    /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
    /* F.S. X adalah elemen terakhir T yang baru */

    /* KAMUS LOKAL */
    int newlastidx;

    /* ALGORITMA */

    if(!IsFull(*T)){
        newlastidx = GetLastIdx(*T) + 1;
        Elmt(*T, newlastidx) = X;
    }
}


void DelLastEl (TabInt *T, ElType *X){
    /* Proses : Menghapus elemen terakhir tabel */
    /* I.S. Tabel tidak kosong */
    /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
    /*      Banyaknya elemen tabel berkurang satu */
    /*      Tabel T mungkin menjadi kosong */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    if(!IsEmpty(*T)){
        *X = Elmt(*T, GetLastIdx(*T));
        Elmt(*T, GetLastIdx(*T)) = ValUndef;
    }
}
