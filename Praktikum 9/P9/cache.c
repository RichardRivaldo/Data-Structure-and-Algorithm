/* Richard Rivaldo - 13519185
Praktikum 9 - List Linier */

#include "listlinier.h"
#include <stdio.h>

int main(){
    List L;
    int n, x, s;
    address P;

    CreateEmpty(&L);

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        InsVLast(&L, i+1);
    }

    scanf("%d", s);
    for(int j = 0; j < s; j++){
        scanf("%d", &x);
        P = Search(L, x);
        if(P == Nil){
            address temp;
            DelLast(&L, &temp);
            printf("miss ");
        }
        else{
            DelP(&L, x);
            printf("hit ");
        }
        InsVFirst(&L, x);
        PrintInfo(L);
        printf("\n");
    }
    return 0;
}
