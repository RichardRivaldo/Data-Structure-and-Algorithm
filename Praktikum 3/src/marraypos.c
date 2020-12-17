/* Richard Rivaldo / 13519185
8 September 2020 / Praktikum 3  */

#include "arraypos.c"
#include <stdio.h>

int main(){

    int X, *Max, *Min;
    int indeks, median;
    TabInt T, sorted;

    BacaIsi(&T);
    TulisIsiTab(T);
    printf("\n");

    scanf("%d", &X);

    sorted = T;
    Sort(&sorted, true);
    Sort(&sorted, true);

    if(NbElmt(T) % 2 == 0){
        median = Elmt(sorted, (NbElmt(T)/2) - 1);
    }
    else{
        median = Elmt(sorted, (NbElmt(T)/2));
    }

    if(SearchB(T, X)){
        indeks = Search1(T, X);
        printf("%d\n", indeks);
        Max = Elmt(T, GetFirstIdx(T));
        Min = Elmt(T, GetFirstIdx(T));
        MaxMin(T, &Max, &Min);
        if(X == *Max){
            printf("maksimum\n");
        }
        else if(X == *Min){
            printf("minimum\n");
        }
        else if(X == median){
            printf("median\n");
        }
    }
    else{
        printf("%d tidak ada\n", X);
    }

    return 0;
}
