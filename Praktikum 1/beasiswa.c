/*
Richard Rivaldo
13519185
Praktikum 1
Membuat program yang membaca IP dan pot dan menentukan kategori
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float IP;
    scanf("%f", &IP);
    float pot;
    scanf("%f", &pot);
    int hasil;

    if(IP >= 3.5){
        hasil = 4;
    }
    else if(IP < 3.5){
        if (pot < 1.0){
            hasil = 1;
        }
        else if((pot >= 1.0) && (pot < 5.0)){
                if (IP >= 2.0){
                    hasil = 3;
                }
                else{
                    hasil = 2;
                }
        }
    }

    printf("%d", hasil);
    return 0;
}
