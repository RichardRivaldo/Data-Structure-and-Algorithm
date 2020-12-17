/* Richard Rivaldo - 13519185
Pra-Praktikum 5 - Matriks */

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
    /* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

boolean IsIdxValid (int i, int j){
    /* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    return ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax));
}

indeks GetFirstIdxBrs (MATRIKS M){
    /* Mengirimkan indeks baris terkecil M */
    return (BrsMin);
}

indeks GetFirstIdxKol (MATRIKS M){
    /* Mengirimkan indeks kolom terkecil M */
    return (KolMin);
}

indeks GetLastIdxBrs (MATRIKS M){
    /* Mengirimkan indeks baris terbesar M */
    return (NBrsEff(M) - 1);
}

indeks GetLastIdxKol (MATRIKS M){
    /* Mengirimkan indeks kolom terbesar M */
    return (NKolEff(M) -1);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    /* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    return((i >= BrsMin && i <= NBrsEff(M) - 1) && (j >= KolMin && j <= NKolEff(M) - 1));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i){
    /* Mengirimkan elemen M(i,i) */
    return (Elmt(M, i, i));
}

void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    /* Melakukan assignment MHsl  MIn */
    int i, j;

    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);

    for(i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++){
        for(j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++){
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}

void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    /* I.S. IsIdxValid(NB,NK) */
    /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
    /* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10
    */
    int i, j;

    MakeMATRIKS(NB, NK, M);

    for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            scanf("%d", &Elmt(*M, i, j));
        }
    }
}

void TulisMATRIKS (MATRIKS M){
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi */
    /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
    int i, j;

    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            if(j != GetLastIdxKol(M)){
                printf("%d ", Elmt(M, i, j));
            }
            else{
                printf("%d", Elmt(M, i, j));
            }
        }
        if(i != GetLastIdxBrs(M)){
            printf("\n");
        }
    }
}

MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
    /* Prekondisi : M1  berukuran sama dengan M2 */
    /* Mengirim hasil penjumlahan matriks: M1 + M2 */
    int i, j;
    MATRIKS hasil;

    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &hasil);

    for(i = GetFirstIdxBrs(hasil); i <= GetLastIdxBrs(hasil); i++){
        for(j = GetFirstIdxKol(hasil); j <= GetLastIdxKol(hasil); j++){
            Elmt(hasil, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
        }
    }
    return hasil;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
    /* Prekondisi : M berukuran sama dengan M */
    /* Mengirim hasil pengurangan matriks: salinan M1 � M2 */
    int i, j;
    MATRIKS hasil;

    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &hasil);

    for(i = GetFirstIdxBrs(hasil); i <= GetLastIdxBrs(hasil); i++){
        for(j = GetFirstIdxKol(hasil); j <= GetLastIdxKol(hasil); j++){
            Elmt(hasil, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
        }
    }
    return hasil;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
    /* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
    /* Mengirim hasil perkalian matriks: salinan M1 * M2 */
    int i, j, k;
    MATRIKS hasil;

    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &hasil);

    for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for(j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++){
            for(k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++){
                Elmt(hasil, i, j) += Elmt(M1, i, k) * Elmt(M2, k, j);
            }
        }
    }
    return hasil;
}

MATRIKS KaliKons (MATRIKS M, ElType X){
    /* Mengirim hasil perkalian setiap elemen M dengan X */
    int i, j;
    MATRIKS hasil;

    MakeMATRIKS(NBrsEff(M), NKolEff(M), &hasil);
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            Elmt(hasil, i, j) = Elmt(M, i, j) * X;
        }
    }
    return hasil;
}

void PKaliKons (MATRIKS * M, ElType K){
    /* I.S. M terdefinisi, K terdefinisi */
    /* F.S. Mengalikan setiap elemen M dengan K */
    MATRIKS hasil = KaliKons(*M, K);
    *M = hasil;
}

boolean EQ (MATRIKS M1, MATRIKS M2){
    /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
    /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
    /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
       dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
    int i, j;

    if((NBrsEff(M1) != NBrsEff(M2)) || (NKolEff(M1) != NKolEff(M2))){
        return false;
    }
    else{
        for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
            for(j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++){
                if(Elmt(M1, i, j) != Elmt(M2, i, j)){
                    return false;
                }
            }
        }
    }
    return true;
}

boolean NEQ (MATRIKS M1, MATRIKS M2){
    /* Mengirimkan true jika M1 tidak sama dengan M2 */
    return (!EQ(M1, M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2){
    /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
    /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
    return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}

int NBElmt (MATRIKS M){
    /* Mengirimkan banyaknya elemen M */
    return (NBrsEff(M) * NKolEff(M));
}

boolean IsBujurSangkar (MATRIKS M){
    /* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
    return (NBrsEff(M) == NKolEff(M));
}

boolean IsSimetri (MATRIKS M){
    /* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
       dan untuk setiap elemen M, M(i,j)=M(j,i) */
    int i, j;
    if(!IsBujurSangkar(M)){
        return false;
    }
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            if(Elmt(M, i, j) != Elmt(M, j, i)){
                return false;
            }
        }
    }
    return true;
}

boolean IsSatuan (MATRIKS M){
    /* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
       setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    int i, j;
    if(!IsBujurSangkar(M)){
        return false;
    }
    else{
        for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
            for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
                if(i == j){
                    if(Elmt(M, i, j) != 1){
                        return false;
                    }
                }
                else{
                    if(Elmt(M, i, j) != 0){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

boolean IsSparse (MATRIKS M){
    /* Mengirimkan true jika M adalah matriks sparse: mariks �jarang� dengan definisi:
       hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int count = 0;
    int i, j;

    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            if(Elmt(M, i, j) != 0){
                count += 1;
            }
        }
    }
    return (count * 20 <= NBElmt(M));
}

MATRIKS Inverse1 (MATRIKS M){
    /* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    return KaliKons(M, -1);
}

float Determinan (MATRIKS M){
    /* Prekondisi: IsBujurSangkar(M) */
    /* Menghitung nilai determinan M */
    int i, j;
    int ukuran = NBrsEff(M);
    float Min[ukuran][ukuran];

    for(i = 0; i < ukuran; i++){
        for(j = 0; j < ukuran; j++){
            Min[i][j] = Elmt(M, i, j);
        }
    }

    int totalTukar = 0;
    float det = 1;
    boolean ditukar;

    while(ukuran > 0){
        ditukar = false;
        i = 0;
        if(Min[ukuran - 1][ukuran - 1] == 0){
            while((i < ukuran - 1) && (!ditukar)){
                if(Min[i][ukuran - 1] == 0){
                    i++;
                }
                else{
                    ditukar = true;
                }
            }
        }
        if((i == (ukuran - 1)) && (ukuran > 1)){
            return 0;
        }
        else if(ditukar){
            for(j = 0; j < ukuran; j++){
                float temp = Min[ukuran - 1][j];
                Min[ukuran - 1][j] = Min[i][j];
                Min[i][j] = temp;
            }
        }
        for(i = 0; i < (ukuran - 1); i++){
            for(j = 0; j < ukuran; j++){
                float pengali = Min[i][ukuran - 1]/Min[ukuran - 1][ukuran - 1];
                Min[i][j] -= pengali * Min[ukuran - 1][j];
            }
        }
        det *= Min[ukuran - 1][ukuran - 1];
        if(ditukar){
            totalTukar += 1;
        }
        ukuran--;
    }
    if(totalTukar % 2 != 0){
        det *= -1;
    }
    else{
        det *= 1;
    }
    if(det < 1 && det > -1){
        return (0.0f);
    }
    else{
        return (det);
    }
}

void PInverse1 (MATRIKS * M){
    /* I.S. M terdefinisi */
    /* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    MATRIKS hasil = Inverse1(*M);
    *M = hasil;
}

void Transpose (MATRIKS * M){
    /* I.S. M terdefinisi dan IsBujursangkar(M) */
    /* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
    int i, j;
    MATRIKS hasil;

    MakeMATRIKS(NKolEff(*M), NBrsEff(*M), &hasil);

    for(i = GetFirstIdxBrs(hasil); i <= GetLastIdxBrs(hasil); i++){
        for(j = GetFirstIdxKol(hasil); j <= GetLastIdxKol(hasil); j++){
            Elmt(hasil, i, j) = Elmt(*M, j, i);
        }
    }
    *M = hasil;
}

float RataBrs (MATRIKS M, indeks i){
    /* Menghasilkan rata-rata dari elemen pada baris ke-i */
    /* Prekondisi: i adalah indeks baris efektif dari M */
    int j;
    float total = 0.0;
    for(j = 0; j <= GetLastIdxKol(M); j++){
        total += Elmt(M, i, j);
    }
    return ((float) total/(float) NKolEff(M));
}

float RataKol (MATRIKS M, indeks j){
    /* Menghasilkan rata-rata dari elemen pada kolom ke-j */
    /* Prekondisi: j adalah indeks kolom efektif dari M */
    int i;
    float total = 0.0;
    for(i = 0; i <= GetLastIdxBrs(M); i++){
        total += Elmt(M, i, j);
    }
    return ((float) total/(float)NBrsEff(M));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
    /* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
    *max = Elmt(M, i, GetFirstIdxKol(M));
    *min = Elmt(M, i, GetFirstIdxKol(M));

    int j;
    for(j = 1; j <= GetLastIdxKol(M); j++){
        if(Elmt(M, i, j) > *max){
            *max = Elmt(M, i, j);
        }
        if(Elmt(M, i, j) < *min){
            *min = Elmt(M, i, j);
        }
    }
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
    /* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
    /* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
    *max = Elmt(M, GetFirstIdxBrs(M), j);
    *min = Elmt(M, GetFirstIdxBrs(M), j);

    int i;
    for(i = 1; i <= GetLastIdxBrs(M); i++){
        if(Elmt(M, i, j) > *max){
            *max = Elmt(M, i, j);
        }
        if(Elmt(M, i, j) < *min){
            *min = Elmt(M, i, j);
        }
    }
}

int CountXBrs (MATRIKS M, indeks i, ElType X){
    /* Menghasilkan banyaknya kemunculan X pada baris i dari M */
    int Count = 0, j;
    for(j = 0; j <= GetLastIdxKol(M); j++){
        if(Elmt(M, i, j) ==  X){
            Count += 1;
        }
    }
    return (Count);
}

int CountXKol (MATRIKS M, indeks j, ElType X){
    /* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
    int Count = 0, i;
    for(i = 0; i <= GetLastIdxBrs(M); i++){
        if(Elmt(M, i, j) ==  X){
            Count += 1;
        }
    }
    return (Count);
}
