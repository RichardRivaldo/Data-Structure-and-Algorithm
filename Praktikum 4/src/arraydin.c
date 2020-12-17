/* Richard Rivaldo / 13519185
Pra-Praktikum 04 - ADT Array Dinamis */

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

void MakeEmpty(TabInt *T, int maxel){
    /* I.S. T sembarang, maxel > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    TI(*T) = (ElType*) malloc(maxel * sizeof(ElType));
    MaxEl(*T) = maxel;
    Neff(*T) = 0;
}

void Dealokasi(TabInt *T){
    /* I.S. T terdefinisi; */
    /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    MaxEl(*T) = 0;
    Neff(*T) = 0;
    free(TI(*T));
}

int NbElmt(TabInt T){
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(Neff(T));
}

int MaxElement(TabInt T){
    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    /* *** Selektor INDEKS *** */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(MaxEl(T));
}

IdxType GetFirstIdx(TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T pertama */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(IdxMin);
}

IdxType GetLastIdx(TabInt T){
    /* Prekondisi : Tabel T tidak kosong */
    /* Mengirimkan indeks elemen T terakhir */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(Neff(T) - 1);
}

boolean IsIdxValid(TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
    /* yaitu antara indeks yang terdefinisi utk container*/

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(i >= IdxMin && i <= MaxEl(T)-1);
}

boolean IsIdxEff(TabInt T, IdxType i){
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
    /* yaitu antara FirstIdx(T)..LastIdx(T) */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

boolean IsEmpty(TabInt T){
    /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(Neff(T) == 0);
}

boolean IsFull(TabInt T){
    /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return(Neff(T) == MaxEl(T));
}

void BacaIsi(TabInt *T){
    /* I.S. T sembarang dan sudah dialokasikan sebelumnya */
    /* F.S. Tabel T terdefinisi */
    /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
          IdxMin satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk T kosong */

    /* KAMUS LOKAL */
    int N, i = IdxMin;
    ElType Elmnt;

    /* ALGORITMA */
    scanf("%d", &N);
    while(N < IdxMin || N > MaxEl(*T)){
        scanf("%d", &N);
    }
    if(N > 0){
        Neff(*T) = N;
        for(i; i < N; i++){
            scanf("%d", &Elmnt);
            Elmt(*T, i) = Elmnt;
        }
    }
}

void TulisIsiTab(TabInt T){
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
    if(IsEmpty(T)){
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

TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
    /* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T1);
    TabInt T3;

    /* ALGORITMA */
    MakeEmpty(&T3, MaxEl(T1));
    Neff(T3) = Neff(T1);

    if(IsEmpty(T1))
        return T2;
    else if(IsEmpty(T2)){
        return T1;
    }
    else{
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
    }

    return T3;
}

boolean IsEQ(TabInt T1, TabInt T2){
    /* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T1);

    /* ALGORITMA */
    if(NbElmt(T1) != NbElmt(T2)){
        return false;
    }
    for(i; i <= GetLastIdx(T1); i++){
        if(Elmt(T1, i) != Elmt(T2, i)){
            return false;
        }
    }
    return true;
}

IdxType Search1(TabInt T, ElType X){
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

boolean SearchB(TabInt T, ElType X){
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

void MaxMin(TabInt T, ElType *Max, ElType *Min){
    /* I.S. Tabel T tidak kosong */
    /* F.S. Max berisi nilai maksimum T;
            Min berisi nilai minimum T */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T);

    /* ALGORITMA */
    *Max = Elmt(T, GetFirstIdx(T));
    *Min = Elmt(T, GetLastIdx(T));

    for(i; i <= GetLastIdx(T); i++){
        if(Elmt(T, i) > *Max){
            *Max = Elmt(T, i);
        }
        if(Elmt(T, i) < *Min){
            *Min = Elmt(T, i);
        }
    }
}

void CopyTab(TabInt Tin, TabInt *Tout){
    /* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
    /* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
    /* Proses : Menyalin isi Tin ke Tout */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(Tin);

    /* ALGORITMA */

    MakeEmpty(Tout, MaxEl(Tin));
    Neff(*Tout) = Neff(Tin);
    for(i; i <= GetLastIdx(*Tout); i++){
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}

ElType SumTab(TabInt T){
    /* Menghasilkan hasil penjumlahan semua elemen T */
    /* Jika T kosong menghasilkan 0 */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T), Count = 0;

    /* ALGORITMA */
    if(!IsEmpty(T)){
        for(i; i <= GetLastIdx(T); i++){
            Count += Elmt(T, i);
        }
    }
    return Count;
}

int CountX(TabInt T, ElType X){
    /* Menghasilkan berapa banyak kemunculan X di T */
    /* Jika T kosong menghasilkan 0 */

    /* KAMUS LOKAL */
    int i = GetFirstIdx(T), Count = 0;

    /* ALGORITMA */
    if(!IsEmpty(T)){
        for(i; i <= GetLastIdx(T); i++){
            if(Elmt(T, i) == X){
                Count += 1;
            }
        }
    }
    return Count;
}

boolean IsAllGenap(TabInt T){
    /* Menghailkan true jika semua elemen T genap. T boleh kosong */

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

void Sort(TabInt *T, boolean asc){
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
        for(i = 0; i <= GetLastIdx(*T); i++){
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
        for(i = 0; i <= GetLastIdx(*T); i++){
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

void AddAsLastEl(TabInt *T, ElType X){
    /* Proses: Menambahkan X sebagai elemen terakhir tabel */
    /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
    /* F.S. X adalah elemen terakhir T yang baru */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    if(IsEmpty(*T) || !IsFull(*T)){
        Neff(*T) += 1;
        Elmt(*T, GetLastIdx(*T)) = X;
    }
}

void DelLastEl(TabInt *T, ElType *X){
    /* Proses : Menghapus elemen terakhir tabel */
    /* I.S. Tabel tidak kosong */
    /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
    /*      Banyaknya elemen tabel berkurang satu */
    /*      Tabel T mungkin menjadi kosong */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T) -= 1;
}

void GrowTab(TabInt *T, int num){
    /* Proses : Menambahkan max element sebanyak num */
    /* I.S. Tabel sudah terdefinisi */
    /* F.S. Ukuran tabel bertambah sebanyak num */

    /* KAMUS LOKAL */
    TabInt temp;
    int i = GetFirstIdx(*T);

    /* ALGORITMA */
    MakeEmpty(&temp, MaxEl(*T) + num);
    Neff(temp) = Neff(*T);

    for(i; i <= GetLastIdx(*T); i++){
        Elmt(temp, i) = Elmt(*T, i);
    }
    Dealokasi(T);
    *T = temp;
}

void ShrinkTab(TabInt *T, int num){
    /* Proses : Mengurangi max element sebanyak num */
    /* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
    /* F.S. Ukuran tabel berkurang sebanyak num. */

    /* KAMUS LOKAL */
    TabInt temp;
    int i = GetFirstIdx(*T);

    /* ALGORITMA */
    MakeEmpty(&temp, MaxEl(*T) - num);
    Neff(temp) = Neff(*T);

    for(i; i <= GetLastIdx(*T); i++){
        Elmt(temp, i) = Elmt(*T, i);
    }
    Dealokasi(T);
    *T = temp;
}

void CompactTab(TabInt *T){
    /* Proses : Mengurangi max element sehingga Neff = MaxEl */
    /* I.S. Tabel tidak kosong */
    /* F.S. Ukuran MaxEl = Neff */

    /* KAMUS LOKAL */
    TabInt temp;
    int i = GetFirstIdx(*T);

    /* ALGORITMA */
    MakeEmpty(&temp, Neff(*T));
    Neff(temp) = Neff(*T);

    for(i; i <= GetLastIdx(*T); i++){
        Elmt(temp, i) = Elmt(*T, i);
    }
    Dealokasi(T);
    *T = temp;
}
