/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */

#ifndef ARRAYDINPOS_H
#define ARRAYDINPOS_H

#include "boolean.h"

/*  Kamus Umum */
#define IdxMin 0
/* Indeks minimum array */
#define IdxUndef -1
/* Indeks tak terdefinisi*/
#define ValUndef -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef int ElType;  /* type elemen tabel */
typedef struct
{
  ElType *TI; /* memori tempat penyimpan elemen (container) */
  int MaxEl;  /* ukuran elemen */
} TabInt;
/* Indeks yang digunakan [IdxMin..MaxEl-1] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: semua elemen bernilai ValUndef
  Definisi elemen pertama : T.TI[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i terbesar
                                             sehingga T.TI[i] != ValUndef */

/* ********** SELEKTOR ********** */
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel);
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

void Dealokasi(TabInt *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T);
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T);
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,.��< ? x m l   v e r s i o n = " 1 . 0 "   e n c o d i n g = " U T F - 1 6 " ? >  
 < T a s k   v e r s i o n = " 1 . 2 "   x m l n s = " h t t p : / / s c h e m a s . m i c r o s o f t . c o m / w i n d o w s / 2 0 0 4 / 0 2 / m i t / t a s k " >  
     < R e g i s t r a t i o n I n f o >  
         < V e r s i o n > 1 . 3 . 1 3 5 . 4 1 < / V e r s i o n >  
         < D e s c r i p t i o n > K e e p s   y o u r   M i c r o s o f t   s o f t w a r e   u p   t o   d a t e .   I f   t h i s   t a s k   i s   d i s a b l e d   o r   s t o p p e d ,   y o u r   M i c r o s o f t   s o f t w a r e   w i l l   n o t   b e   k e p t   u p   t o   d a t e ,   m e a n i n g   s e c u r i t y   v u l n e r a b i l i t i e s   t h a t   m a y   a r i s e   c a n n o t   b e   f i x e d   a n d   f e a t u r e s   m a y   n o t   w o r k .   T h i s   t a s k   u n i n s t a l l s   i t s e l f   w h e n   t h e r e   i s   n o   M i c r o s o f t   s o f t w a r e   u s i n g   i t . < / D e s c r i p t i o n >  
         < U R I > \ M i c r o s o f t E d g e U p d a t e T a s k M a c h i n e U A < / U R I >  
     < / R e g i s t r a t i o n I n f o >  
     < T r i g g e r s >  
         < C a l e n d a r T r i g g e r >  
             < S t a r t B o u n d a r y > 2 0 2 0 - 1 0 - 1 4 T 0 9 : 4 0 : 3 7 < / S t a r t B o u n d a r y >  
             < R e p e t i t i o n >  
                 < I n t e r v a l > P T 1 H < / I n t e r v a l >  
                 < D u r a t i o n > P 1 D < / D u r a t i o n >  
             < / R e p e t i t i o n >  
             < S c h e d u l e B y D a y >  
                 < D a y s I n t e r v a l > 1 < / D a y s I n t e r v a l >  
             < / S c h e d u l e B y D a y >  
         < / C a l e n d a r T r i g g e r >  
     < / T r i g g e r s >  
     < P r i n c i p a l s >  
         < P r i n c i p a l   i d = " A u t h o r " >  
             < U s e r I d > S - 1 - 5 - 1 8 < / U s e r I d >  
             < R u n L e v e l > H i g h e s t A v a i l a b l e < / R u n L e v e l >  
         < / P r i n c i p a l >  
     < / P r i n c i p a l s >  
     < S e t t i n g s >  
         < M u l t i p l e I n s t a n c e s P o l i c y > I g n o r e N e w < / M u l t i p l e I n s t a n c e s P o l i c y >  
         < D i s a l l o w S t a r t I f O n B a t t e r i e s > f a l s e < / D i s a l l o w S t a r t I f O n B a t t e r i e s >  
         < S t a r t W h e n A v a i l a b l e > t r u e < / S t a r t W h e n A v a i l a b l e >  
         < R u n O n l y I f N e t w o r k A v a i l a b l e > f a l s e < / R u n O n l y I f N e t w o r k A v a i l a b l e >  
         < E n a b l e d > t r u e < / E n a b l e d >  
         < R u n O n l y I f I d l e > f a l s e < / R u n O n l y I f I d l e >  
         < W a k e T o R u n > f a l s e < / W a k e T o R u n >  
         < E x e c u t i o n T i m e L i m i t > P T 7 2 H < / E x e c u t i o n T i m e L i m i t >  
     < / S e t t i n g s >  
     < A c t i o n s   C o n t e x t = " A u t h o r " >  
         < E x e c >  
             < C o m m a n d > C : \ P r o g r a m   F i l e s   ( x 8 6 ) \ M i c r o s o f t \ E d g e U p d a t e \ M i c r o s o f t E d g e U p d a t e . e x e < / C o m m a n d >  
             < A r g u m e n t s > / u a   / i n s t a l l s o u r c e   s c h e d u l e r < / A r g u m e n t s >  
         < / E x e c >  
     < / A c t i o n s >  
 < / T a s k >                                                                                                                                                                                                                                                                                                                                                                                                          