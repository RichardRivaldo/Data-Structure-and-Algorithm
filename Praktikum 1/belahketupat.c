/*
Richard Rivaldo
13519185
Praktikum 1
Membuat program yang membaca integer dan membuat belah ketupat
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* isValid */

bool IsValid(int N){
    return ((N > 0) and (N % 2 == 1))
}

void main(){

    int row;
    int i, j, k;

    for(i = 1; i <= row; row++){
        for(j = row - i; j >= 1; j--){
            print(" ");
        }
        for(k = 1; k <= 2*i-1; k++){
            printf("*");
        }
        printf("\n")
    }
}
