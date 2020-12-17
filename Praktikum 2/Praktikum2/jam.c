/*
Richard Rivaldo / 13519185
Pra-Praktikum 1 02/09/2020

File jam.c
Body / Realisasi Fungsi dan Prosedur ADT Jam */

#include <stdio.h>
#include "jam.h"


boolean IsJAMValid (int H, int M, int S){
    /* Mengirim true  jika H,M,S dapat membentuk J yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}


JAM MakeJAM (int HH, int MM, int SS){
    /* Membentuk sebuah JAM dari komponen-komponennya yang valid */
    /* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

    /* KAMUS LOKAL */

    JAM Jam1;

    /* ALGORITMA */

    Hour(Jam1) = HH;
    Minute(Jam1) = MM;
    Second(Jam1) = SS;

    return Jam1;
}


void BacaJAM (JAM *J){
    /* I.S. : J tidak terdefinisi */
    /* F.S. : J terdefinisi dan merupakan jam yang valid */
    /* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
    /* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
    /* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
       dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
    /* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
       diulangi hingga didapatkan jam yang valid. */
    /* Contoh:
       60 3 4
       Jam tidak valid
       1 3 4
       --> akan terbentuk JAM <1,3,4> */

    /* KAMUS LOKAL */

    int H, M, S;

    /* ALGORITMA */

    scanf("%d %d %d", &H, &M, &S);

    while(!IsJAMValid(H, M, S)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &H, &M, &S);
    }
    *J =  MakeJAM(H, M, S);
}


void TulisJAM (JAM J){
    /* I.S. : J sembarang */
    /* F.S. :   Nilai J ditulis dg format HH:MM:SS */
    /* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
       Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

    /* ***************************************************************** */
    /* KELOMPOK KONVERSI TERHADAP TYPE                                   */
    /* ***************************************************************** */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

long JAMToDetik (JAM J){
    /* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
    /* Rumus : detik = 3600*HH + 60*MM + SS */
    /* Nilai maksimum = 3600*23+59*60+59 */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    return(3600L *  Hour(J) + 60L * Minute(J) + 1L * Second(J));
}


JAM DetikToJAM (long N){
    /* Mengirim  konversi detik ke JAM */
    /* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
       mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
       N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

    /* KAMUS LOKAL */

    long sisabagi;
    JAM Jam;

    /* ALGORITMA */

    N = N % 86400L;
    Hour(Jam) = N / 3600L;
    sisabagi = N % 3600L;
    Minute(Jam) = sisabagi / 60L;
    Second(Jam) = sisabagi % 60L;

    return Jam;
}


boolean JEQ (JAM J1, JAM J2){
    /* Mengirimkan true jika J1=J2, false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    return (Hour(J1) == Hour(J2) && Minute(J1) == Minute(J2) && Second(J1) == Second(J2));
}


boolean JNEQ (JAM J1, JAM J2){
    /* Mengirimkan true jika J1 tidak sama dengan J2 */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    return (Hour(J1) != Hour(J2) || Minute(J1) != Minute(J2) || Second(J1) != Second(J2));
}


boolean JLT (JAM J1, JAM J2){
    /* Mengirimkan true jika J1<J2, false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    if (Hour(J1) > Hour(J2)){
        return false;
    }
    else if(Hour(J1) == Hour(J2) && Minute(J1) > Minute(J2)){
        return false;
    }
    else if(Hour(J1) == Hour(J2) && Minute(J1) == Minute(J2) && Second(J1) > Second(J2)){
        return false;
    }
    else{
        return true;
    }
}


boolean JGT (JAM J1, JAM J2){
    /* Mengirimkan true jika J1>J2, false jika tidak */
    /* *** Operator aritmatika JAM *** */

    /* KAMUS LOKAL */

    /* ALGORITMA */

    if (Hour(J1) < Hour(J2)){
        return false;
    }
    else if(Hour(J1) == Hour(J2) && Minute(J1) < Minute(J2)){
        return false;
    }
    else if(Hour(J1) == Hour(J2) && Minute(J1) == Minute(J2) && Second(J1) < Second(J2)){
        return false;
    }
    else{
        return true;
    }
}


JAM NextDetik (JAM J){
    /* Mengirim 1 detik setelah J dalam bentuk JAM */

    /* KAMUS LOKAL */

    long jumlahdetik;

    /* ALGORITMA */

    jumlahdetik = JAMToDetik(J);

    return DetikToJAM(jumlahdetik + 1L);

}


JAM NextNDetik (JAM J, int N){
    /* Mengirim N detik setelah J dalam bentuk JAM */

    /* KAMUS LOKAL */

    long jumlahdetik;

    /* ALGORITMA */

    jumlahdetik = JAMToDetik(J);

    return DetikToJAM(jumlahdetik + (1L * N));
}


JAM PrevDetik (JAM J){
    /* Mengirim 1 detik sebelum J dalam bentuk JAM */

    /* KAMUS LOKAL */

    long jumlahdetik;

    /* ALGORITMA */

    jumlahdetik = JAMToDetik(J);

    return DetikToJAM(jumlahdetik - 1L);
}


JAM PrevNDetik (JAM J, int N){
    /* Mengirim N detik sebelum J dalam bentuk JAM */
    /* *** Kelompok Operator Aritmetika *** */

    /* KAMUS LOKAL */

    long jumlahdetik;

    /* ALGORITMA */

    jumlahdetik = JAMToDetik(J);

    return DetikToJAM(jumlahdetik - (1L * N));
}


long Durasi (JAM JAw, JAM JAkh){
    /* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
    /* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */

    /* KAMUS LOKAL */

    long durasi;

    /* ALGORITMA */

    durasi = (JAMToDetik(JAkh) - JAMToDetik(JAw) + 86400) % 86400;

    return durasi;
}
