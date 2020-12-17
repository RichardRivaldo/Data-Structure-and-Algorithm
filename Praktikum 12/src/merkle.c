/* Richard Rivaldo/13519185
Praktikum 12 Tree */

#include "bintree.h"
#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    /* Create Merkle Tree */
    BinTree Merkle(int koefH){
        if(koefH == 0){
            int elmt;
            scanf("%d", &elmt);
            return(AlokNode(elmt));
        }

        BinTree MerkleTree = AlokNode(0);

        Left(MerkleTree) = Merkle(koefH - 1); Right(MerkleTree) = Merkle(koefH - 1);
        Akar(MerkleTree) = Info(Right(MerkleTree)) + Info(Left(MerkleTree));

        return MerkleTree;
    }

    int InputN;
    scanf("%d", &InputN);

    /* Cek input */
    int j = 0; long i = 1;

    while(i < InputN){
        j++;
        i *= 2;
    }

    /* Invalid */
    if(i != InputN){
        printf("Jumlah masukan tidak sesuai\n");
        return 0;
    }

    BinTree MerkleTree = Merkle(j); int H = 2; /* Print Tree */
    PrintTree(MerkleTree, H);

    return 0;
}
