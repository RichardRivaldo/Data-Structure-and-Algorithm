#include "mesinkar.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
    while (CC == BLANK){
        ADV();
    }
}
void STARTKATA(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

    START();
    IgnoreBlank();
    if(CC==MARK){
        EndKata = true;
    }
    else{
        EndKata = false;
        SalinKata();
    }

}
void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    }
    else{
        SalinKata();
    }
}
void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i=0;

    while ((CC!=MARK) && (CC != BLANK) && (i < NMax)){
        CKata.TabKata[i]=CC;
        ADV();
        i++;
    }

    IgnoreBlank();
    if (CC == MARK){
            EndKata = true;
    }

    CKata.Length = i;
}
