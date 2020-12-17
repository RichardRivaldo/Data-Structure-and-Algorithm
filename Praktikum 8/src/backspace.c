/* Richard Rivaldo - 13519185
Praktikum 8 - Stack */

#include "stackt.h"
#include <stdio.h>

int main(){
    int N, M, i = 0, j = 0;
    int X, Y;
    Stack S, T;

    CreateEmpty(&S);
    CreateEmpty(&T);

    scanf("%d %d", &N, &M);
    for(i; i < N; i++){
        scanf("%d", &X);

        if(X != 0){
            Push(&S, X);
        }
        else{
            if(!IsEmpty(S)){
                Pop(&S, &X);
            }
        }
    }

    for(j; j < M; j++){
        scanf("%d", &Y);

        if(Y != 0){
            Push(&T, Y);
        }
        else{
            if(!IsEmpty(T)){
                Pop(&T, &Y);
            }
        }
    }

    while(!IsEmpty(S) && !IsEmpty(T)){
        Pop(&S, &X);
        Pop(&T, &Y);
        if(X != Y){
            Push(&T, Y);
            break;
        }
    }
    if(IsEmpty(S) && IsEmpty(T)){
        printf("Sama\n");
    }
    else{
        printf("Tidak sama\n");
    }

    return 0;
}
