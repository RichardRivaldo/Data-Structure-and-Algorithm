/*
Richard Rivaldo
13519185
Praktikum 1
Membuat file yang mengkonversi suhu dari celsius
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float tingkatsuhu;
    scanf("%f\n", &tingkatsuhu);
    char namasuhu;
    scanf("%c", &namasuhu);
    float hasilkonversi;

    if (namasuhu == 'R'){
        hasilkonversi = 0.8 * tingkatsuhu;
    }
    else if (namasuhu == 'F'){
        hasilkonversi = (1.8 * tingkatsuhu) + 32;
    }
    else if(namasuhu == 'K'){
        hasilkonversi = tingkatsuhu + 273.15;
    }
    printf("%.2f", hasilkonversi);
    return 0;
}
