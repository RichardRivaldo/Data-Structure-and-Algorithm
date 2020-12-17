#include "listsirkuler.c"
#include <stdio.h>

int main(){
    List L;
    infotype X = 6;
    CreateEmpty(&L);

    address P = Alokasi(4);
    address Q = Alokasi(5);
    address S = Alokasi(6);
    InsertFirst(&L, P);
    InsertFirst(&L, Q);
    InsertLast(&L, S);

    PrintInfo(L);

    address Z = Search(L, 6);
    if(Z == Nil){
        printf("NIL");
    }
    //DelVFirst(&L, &X);
    //printf("%d", X);
    DelP(&L,X);

    PrintInfo(L);
}
