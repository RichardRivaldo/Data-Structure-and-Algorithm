/* Richard Rivaldo / 13519185
Praktikum 04 Array Dinamis Eksplisit */

#include <stdio.h>
#include <stdlib.h>
#include "arraydinpos.h"


void MakeEmpty(TabInt *T, int maxel){
    /* I.S. T sembarang, maxel > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    /* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

    TI(*T) = (ElType*) malloc(maxel * sizeof(ElType));
    MaxEl(*T) = maxel;
    int i = IdxMin;
    for(i; i <= maxel - 1; i++){
        Elmt(*T, i) = ValUndef;
    }
}

void Dealokasi(TabInt *T){
    /* I.S. T terdefinisi; */
    /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

    int i = IdxMin;
    MaxEl(*T) = 0;
    free(TI(*T));
}

int NbElmt(TabInt T){

    int i = IdxMin;
    int Count = 0;

    for(i; i < MaxEl(T); i++){
        if(Elmt(T, i) != ValUndef){
            Count += 1;
        }
    }
    return Count;
}

int MaxElement(TabInt T){

    return MaxEl(T);
}

IdxType GetFirstIdx(TabInt T){

    return IdxMin;
}

IdxType GetLastIdx(TabInt T){
    return(NbElmt(T) - 1);
}

boolean IsIdxValid(TabInt T, IdxType i){
    return(i >= IdxMin && i <= MaxEl(T) - 1);
}

boolean IsIdxEff(TabInt T, IdxType i){
    return(i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

boolean IsEmpty(TabInt T){
    return(NbElmt(T) == 0);
}

boolean IsFull(TabInt T){
    return(NbElmt(T) == MaxEl(T));
}

void BacaIsi(TabInt *T){
    int N, i = IdxMin;
    ElType Elmnt;

    scanf("%d", &N);
    while(N < IdxMin || N > MaxEl(*T)){
        scanf("%d", &N);
    }
    if(N > 0){
        for(i; i < N; i++){
            scanf("%d", &Elmnt);
            Elmt(*T, i) = Elmnt;
        }
    }
}

void TulisIsiTab(TabInt T){
    int i = GetFirstIdx(T);

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
    int i = GetFirstIdx(T1);
    TabInt T3;

    MakeEmpty(&T3, MaxEl(T1));

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

    int i = GetFirstIdx(T1);

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
    int i = GetFirstIdx(T);

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
    int i = GetFirstIdx(T);

    for(i; i <= GetLastIdx(T); i++){
        if(Elmt(T, i) == X){
            return true;
        }
    }
    return false;
}

void MaxMin(TabInt T, ElType *Max, ElType *Min){
    int i = GetFirstIdx(T);

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
    int i = GetFirstIdx(Tin);

    MakeEmpty(Tout, MaxEl(Tin));
    for(i; i <= GetLastIdx(Tin); i++){
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}

ElType SumTab(TabInt T){
    int i = GetFirstIdx(T), Count = 0;

    if(!IsEmpty(T)){
        for(i; i <= GetLastIdx(T); i++){
            Count += Elmt(T, i);
        }
    }
    return Count;
}

int CountX(TabInt T, ElType X){
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
    if(IsEmpty(*T) || !IsFull(*T)){
        Elmt(*T, GetLastIdx(*T) + 1) = X;
    }
}

void DelLastEl(TabInt *T, ElType *X){
    *X = Elmt(*T, GetLastIdx(*T));
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
}

void GrowTab(TabInt *T, int num){
    TabInt temp;
    int i = GetFirstIdx(*T);

    /* ALGORITMA */
    MakeEmpty(&temp, MaxEl(*T) + num);

    for(i; i <= GetLastIdx(*T); i++){
        Elmt(temp, i) = Elmt(*T, i);
    }
    Dealokasi(T);
    *T = temp;
}

void ShrinkTab(TabInt *T, int num){
    TabInt temp;
    int i = GetFirstIdx(*T);

    /* ALGORITMA */
    MakeEmpty(&temp, MaxEl(*T) - num);

    for(i; i <= GetLastIdx(*T); i++){
        Elmt(temp, i) = Elmt(*T, i);
    }
    Dealokasi(T);
    *T = temp;
}

void CompactTab(TabInt *T){
    TabInt temp;
    int i = GetFirstIdx(*T);

    /* ALGORITMA */
    MakeEmpty(&temp, MaxEl(*T));

    for(i; i <= GetLastIdx(*T); i++){
        Elmt(temp, i) = Elmt(*T, i);
    }
    Dealokasi(T);
    *T = temp;
}
