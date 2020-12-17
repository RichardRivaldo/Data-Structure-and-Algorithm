/* Richard Rivaldo/13519185
Praktikum 12 Tree */

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

void InvertBtree(BinTree *P){
    /* I.S. Pohon P Terdefinisi */
    /* F.S. Pohon P diflip secara vertikal */
    /*      Contoh:
            1
          2   5
          3 4 6
         Menjadi:
            1
          5   2
          6 4 3 */

    if(IsUnerLeft(*P)){
        Right(*P) = Left(*P); Left(*P) = Nil;
        InvertBtree(&Right(*P));
    }
    else if(IsUnerRight(*P)){
        Left(*P) = Right(*P); Right(*P) = Nil;
        InvertBtree(&Left(*P));
    }
    else if(IsBiner(*P)){
        BinTree tempRight = Right(*P);

        Right(*P) = Left(*P); Left(*P) = tempRight;
        InvertBtree(&Right(*P)); InvertBtree(&Left(*P));
    }
}
