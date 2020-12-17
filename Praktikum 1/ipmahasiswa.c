/*
Richard Rivaldo
13519185
Praktikum 1
Membuat program yang membaca IP dan menentukan mahasiswa lulus dan tidak lulus
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* function IsWithinRange (X : real; min, max : real) -> boolean
{ Menghasilkan true jika min <= X <= max, menghasilkan false jika tidak }*/


bool IsWithinRange(float X, float min, float max){

    if ((X >= min) && (X <= max)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    float min = 0.00;
    float max = 4.00;
    float nilaiIP;
    scanf("%f\n", &nilaiIP);

    float totalIP = 0;
    int jumlahMahasiswa = 0;
    int lulus = 0;
    int tidaklulus = 0;
    float rataIP;

    if (nilaiIP == -999){
            printf("Tidak ada data yang dimasukkan\n");
    }
    else{
            while (nilaiIP != -999){
                scanf("%f\n", &nilaiIP);
                if (IsWithinRange(nilaiIP, min, max)){
                    totalIP += nilaiIP;
                    jumlahMahasiswa ++;
                    rataIP = totalIP / jumlahMahasiswa;
                    if (nilaiIP >= 2.75){
                        lulus ++;
                    }
                    else{
                        tidaklulus ++;
                    }
                }
            }
    }

    printf("%d\n", jumlahMahasiswa);
    printf("%d\n", lulus);
    printf("%d\n", tidaklulus);
    printf("%.2f\n", rataIP);

    return 0;
}
