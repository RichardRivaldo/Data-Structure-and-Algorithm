#include "queuelist.c"
#include <stdio.h>

int main(){
    Queue Q;
    /*address P;
    Alokasi(&P, 5); */
    infotype X;
    CreateEmpty(&Q);

    Enqueue(&Q, 5);
    Enqueue(&Q, 10);
    Dequeue(&Q, &X);
    printf("%d\n", InfoHead(Q));

    address P = Head(Q);
    while(P != Nil){
        printf("%d\n", Info(P));
        P = Next(P);
    }
}
