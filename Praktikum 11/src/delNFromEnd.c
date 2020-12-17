/* Richard Rivaldo - 13519185
Praktikum 11 - List Rekursif */

#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

List delNFromEnd(List L, int n){
    /* L terdefinisi, tidak mungkin kosong. */
    /* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
       lalu mengembalikan head dari list
       misal L = [1, 2, 3, 4, 5] dan n = 2
             L akan menjadi [1, 2, 3, 5] */
    int NbElmt = NbElmtList(L);
    address Deleted;
    address Del[100];
    int idxDel = NbElmt - n;

    if(IsOneElmt(L)){
        Deleted = (L);
        Dealokasi(Deleted);
        return Nil;
    }
    else if(n == NbElmt){
        Deleted = (L);
        L = Tail(L);
        Dealokasi(Deleted);
        return L;
    }
    else{
        int i = 0;
        address P = (L);
        while((P) != Nil){
            Del[i] = P;
            i++;
            SetNext(P, P);
        }
        SetNext(Del[idxDel-1], Del[idxDel + 1]);
        Dealokasi(Del[idxDel]);
        return L;
    }
}
