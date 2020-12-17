/* Richard Rivaldo/13519185
Pra Praktikum 12 - Binary Tree */

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree Tree(infotype Akar, BinTree L, BinTree R){
    /* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
    /* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
    BinTree tree = (BinTree) malloc(sizeof(BinTree));

    if(tree != Nil){
        Akar(tree) = Akar; Left(tree) = L; Right(tree) = R;
        return tree;
    }
    else{
        return Nil;
    }
}

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P){
    /* I.S. Akar, L, R terdefinisi. P Sembarang */
    /* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
            jika alokasi berhasil. P = Nil jika alokasi gagal. */
    *P = Tree(Akar, L, R);
}

BinTree BuildBalanceTree(int n){
    /* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
    if(n == 0){
        return Nil;
    }
    else{
        int root;
        scanf("%d", &root);
        int nLeft = n/2, nRight = n - nLeft - 1;
        BinTree NewL = BuildBalanceTree(nLeft);
        BinTree NewR = BuildBalanceTree(nRight);
        return Tree(root, NewL, NewR);
    }
}

addrNode AlokNode(infotype X){
    /* Mengirimkan addrNode hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
      maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    addrNode NewNode = (addrNode) malloc(sizeof(Node));

    if(NewNode != Nil){
        Akar(NewNode) = X;
        Left(NewNode) = Nil; Right(NewNode) = Nil;
        return NewNode;
    }
    else{
        return Nil;
    }
}

void DealokNode(addrNode P){
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian addrNode P */
    free(P);
}

boolean IsTreeEmpty(BinTree P){
    /* Mengirimkan true jika P adalah pohon biner kosong */
    return P == Nil;
}

boolean IsTreeOneElmt(BinTree P){
    /* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
    if(IsTreeEmpty(P)){
        return false;
    }
    else{
        return(IsTreeEmpty(Left(P)) && IsTreeEmpty(Right(P)));
    }
}

boolean IsUnerLeft(BinTree P){
    /* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
    if(IsTreeEmpty(P)){
        return false;
    }
    else{
        return((Left(P) != Nil) && (Right(P) == Nil));
    }
}

boolean IsUnerRight(BinTree P){
    /* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
    if(IsTreeEmpty(P)){
        return false;
    }
    else{
        return((Left(P) == Nil) && (Right(P) != Nil));
    }
}

boolean IsBiner(BinTree P){
    /* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
    if(IsTreeEmpty(P)){
        return false;
    }
    else{
        return(Left(P) != Nil && Right(P) != Nil);
    }
}

void PrintPreorder(BinTree P){
    /* I.S. P terdefinisi */
    /* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
       Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
       Pohon kosong ditandai dengan ().
       Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh:
       (A()()) adalah pohon dengan 1 elemen dengan akar A
       (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
    printf("(");
    if(!IsTreeEmpty(P)){
        printf("%d", Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
    }
    printf(")");
}

void PrintInorder(BinTree P){
    /* I.S. P terdefinisi */
    /* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
       Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
       Pohon kosong ditandai dengan ().
       Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh:
       (()A()) adalah pohon dengan 1 elemen dengan akar A
       ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
    printf("(");
    if(!IsTreeEmpty(P)){
        PrintInorder(Left(P));
        printf("%d", Akar(P));
        PrintInorder(Right(P));
    }
    printf(")");
}

void PrintPostorder(BinTree P){
    /* I.S. P terdefinisi */
    /* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
       Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
       Pohon kosong ditandai dengan ().
       Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
    /* Contoh:
       (()()A) adalah pohon dengan 1 elemen dengan akar A
       ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
    printf("(");
    if(!IsTreeEmpty(P)){
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d", Akar(P));
    }
    printf(")");
}

void IndentPrint(BinTree P, int h, int Indent){
    if(!IsTreeEmpty(P)){
        printf("%*s%d\n", Indent, "", Akar(P));

        IndentPrint(Left(P), h, Indent + h);
        IndentPrint(Right(P), h, Indent + h);
    }
}

void PrintTree(BinTree P, int h){
    /* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
    /* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
    /* Penulisan akar selalu pada baris baru (diakhiri newline) */
    /* Contoh, jika h = 2:
    1) Pohon preorder: (A()()) akan ditulis sbb:
    A
    2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
    A
      B
      C
    3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
    A
      B
        D
      C
        E
    */
    IndentPrint(P, h, 0);
}

boolean SearchTree(BinTree P, infotype X){
    /* Mengirimkan true jika ada node dari P yang bernilai X */
    if(IsTreeEmpty(P)){
        return false;
    }
    else if(Akar(P) == X){
        return true;
    }
    else{
        return(SearchTree(Left(P), X) || SearchTree(Right(P), X));
    }
}

int NbElmt(BinTree P){
    /* Mengirimkan banyaknya elemen (node) pohon biner P */
    if(IsTreeEmpty(P)){
        return 0;
    }
    else{
        return NbElmt(Left(P)) + NbElmt(Right(P)) + 1;
    }
}

int NbDaun(BinTree P){
    /* Mengirimkan banyaknya daun (node) pohon biner P */
    /* Prekondisi: P tidak kosong */
    if(IsTreeEmpty(P)){
        return 0;
    }
    else{
        if(IsTreeOneElmt(P)){
            return 1;
        }
        if(IsUnerLeft(P)){
            return(NbDaun(Left(P)));
        }
        else if(IsUnerRight(P)){
            return(NbDaun(Right(P)));
        }
        else{
            return(NbDaun(Left(P)) + NbDaun(Right(P)));
        }
    }
}

boolean IsSkewLeft(BinTree P){
    /* Mengirimkan true jika P adalah pohon condong kiri */
    /* Pohon kosong adalah pohon condong kiri */
    if(IsTreeEmpty(P)){
        return true;
    }
    else{
        if(IsUnerRight(P) || IsBiner(P)){
            return false;
        }
        else{
            return(IsSkewLeft(Left(P)));
        }
    }
}

boolean IsSkewRight(BinTree P){
    /* Mengirimkan true jika P adalah pohon condong kanan */
    /* Pohon kosong adalah pohon condong kanan */
    if(IsTreeEmpty(P)){
        return true;
    }
    else{
        if(IsUnerLeft(P) || IsBiner(P)){
            return false;
        }
        else{
            return(IsSkewRight(Right(P)));
        }
    }
}

int Level(BinTree P, infotype X){
    /* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
       Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
    if(Akar(P) == X){
        return 1;
    }
    else{
        if(SearchTree(Right(P), X)){
            return(1 + Level(Right(P), X));
        }
        else{
            return(1 + Level(Left(P), X));
        }
    }
}

int Tinggi(BinTree P){
    /* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
       Mengirim "height" yaitu tinggi dari pohon */
    if(IsTreeEmpty(P)){
        return 0;
    }
    else{
        if(Tinggi(Left(P)) >= Tinggi(Right(P))){
            return(Tinggi(Left(P)) + 1);
        }
        else{
            return(Tinggi(Right(P)) + 1);
        }
    }
}

void AddDaunTerkiri(BinTree *P, infotype X){
    /* I.S. P boleh kosong */
    /* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
    if(IsTreeEmpty(*P)){
        *P = Tree(X, Nil, Nil);
    }
    else{
        AddDaunTerkiri(&Left(*P), X);
    }
}

void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri){
    /* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
    /* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
            sebagai anak Kanan X (jika Kiri = false) */
    /*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
    if(Akar(*P) == X && IsTreeOneElmt(*P)){
        if(Kiri){
            Left(*P) = Tree(Y, Nil, Nil);
        }
        else{
            Right(*P) = Tree(Y, Nil, Nil);
        }
    }
    else{
        if(SearchTree(Left(*P), X)){
            AddDaun(&Left(*P), X, Y, Kiri);
        }
        else{
            AddDaun(&Right(*P), X, Y, Kiri);
        }
    }
}

void DelDaunTerkiri(BinTree *P, infotype *X){
    /* I.S. P tidak kosong */
    /* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
            disimpan pada daun terkiri yang dihapus */
    if(IsTreeOneElmt(*P)){
        *X = Akar(*P);
        addrNode Temp = *P;
        *P = Nil;
        DealokNode(Temp);
    }
    else{
        if(IsUnerRight(*P)){
            DelDaunTerkiri(&Right(*P), X);
        }
        else{
            DelDaunTerkiri(&Left(*P), X);
        }
    }
}

void DelDaun(BinTree *P, infotype X){
    /* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
    /* F.S. Semua daun bernilai X dihapus dari P. */
    if(!IsTreeEmpty(*P)){
        if(IsTreeOneElmt(*P)){
            if(Akar(*P) == X){
                addrNode Temp = *P;
                *P = Nil;
                DealokNode(Temp);
            }
        }
        else{
            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}

List MakeListDaun(BinTree P){
    /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
    /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
       jika semua alokasi list berhasil.
       Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
       Menghasilkan list kosong jika ada alokasi yang gagal. */
    if(IsTreeEmpty(P)){
        return Nil;
    }
    else if(IsTreeOneElmt(P)){
        return Alokasi(Akar(P));
    }
    else{
        List rightList = MakeListDaun(Right(P));
        List leftList = MakeListDaun(Left(P));
        return Concat(leftList, rightList);
    }
}

List MakeListPreorder(BinTree P){
    /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
    /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
       dengan urutan preorder, jika semua alokasi berhasil.
       Menghasilkan list kosong jika ada alokasi yang gagal. */
    if(IsTreeEmpty(P)){
        return Nil;
    }
    else{
        List rightList = MakeListPreorder(Right(P));
        List leftList = MakeListPreorder(Left(P));
        return(Concat(Konso(Akar(P), leftList), rightList));
    }
}

List MakeListLevel(BinTree P, int N){
    /* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
    /* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P
       yang levelnya=N, jika semua alokasi berhasil.
       Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
       Menghasilkan list kosong jika ada alokasi yang gagal. */
    if(IsTreeEmpty(P)){
        return Nil;
    }
    if(N == 1){
        return Alokasi(Akar(P));
    }
    else{
        List rightList = MakeListLevel(Right(P), N - 1);
        List leftList = MakeListLevel(Left(P), N - 1);

        return(Concat(leftList, rightList));
    }
}

boolean BSearch(BinTree P, infotype X){
    /* Mengirimkan true jika ada node dari P yang bernilai X */
    if(IsTreeEmpty(P)){
        return false;
    }
    else if(Akar(P) == X){
        return true;
    }
    if(Akar(P) > X){
        return BSearch(Left(P), X);
    }
    else{
        return BSearch(Right(P), X);
    }
}

void InsSearch(BinTree *P, infotype X){
    /* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X.
    Belum ada simpul P yang bernilai X. */
    if(IsTreeEmpty(*P)){
        *P = AlokNode(X);
    }
    else{
        if(X >= Akar(*P)){
            InsSearch(&Right(*P), X);
        }
        else{
            InsSearch(&Left(*P), X);
        }
    }
}

void DeleteNode(BinTree *P){
    if(Right(*P) !=  Nil){
        DeleteNode(&Right(*P));
    }
    else{
        *P = Left(*P);
    }
}

void DelBtree(BinTree *P, infotype X){
    /* I.S. Pohon P tidak  kosong */
    /* F.S. Nilai X yang dihapus pasti ada */
    /* Sebuah node dengan nilai X dihapus */
    if(X > Akar(*P)){
        DelBtree(&Right(*P), X);
    }
    else if(X < Akar(*P)){
        DelBtree(&Left(*P), X);
    }
    else{
        if(IsTreeOneElmt(*P)){
            *P = Nil;
        }
        if(IsBiner(*P)){
            DeleteNode(&Left(*P));
        }
        if(IsUnerLeft(*P)){
            *P = Left(*P);
        }
        if(IsUnerRight(*P)){
            *P = Right(*P);
        }
    }
}
