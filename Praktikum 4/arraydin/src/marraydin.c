/* Richard Rivaldo / 13519185
Praktikum 04 Array Dinamis Eksplisit */

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

int main(){

    TabInt T;
    int maxelmt, N, Q, op, i = 0;
    int num;

    scanf("%d", &maxelmt);
    MakeEmpty(&T, maxelmt);

    BacaIsi(&T);

    scanf("%d", &Q);

    for(i; i < Q; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &num);
            if(IsFull(T)){
                printf("array sudah penuh\n");
            }
            else{
                AddAsLastEl(&T, num);
                printf("%d", MaxEl(T)); TulisIsiTab(T);
                printf("\n");
            }
        }
        else if(op == 2){
            scanf("%d", &num);
            GrowTab(&T, num);
            printf("%d", MaxEl(T)); TulisIsiTab(T);
            printf("\n");
        }
        else if(op == 3){
            scanf("%d", &num);
            if(MaxEl(T) < num){
                printf("array terlalu kecil\n");
            }
            else{
                ShrinkTab(&T, num);
                printf("%d", MaxEl(T)); TulisIsiTab(T);
                printf("\n");
            }
        }
        else if(op == 4){
            CompactTab(&T);
            printf("%d", MaxEl(T)); TulisIsiTab(T);
            printf("\n");
        }
    }
    return 0;
}
