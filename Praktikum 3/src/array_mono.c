/* Richard Rivaldo / 13519185
8 September 2020 / Pra-Praktikum 3  */


#include "arraypos.c"
#include <stdio.h>

int main(){

    TabInt T, sortmengecil, sortmembesar;
    int i = GetFirstIdx(T);
    boolean mengecil = false, membesar = false;


    BacaIsi(&T);


    sortmembesar = T;
    sortmengecil = T;
    Sort(&sortmengecil, false);
    Sort(&sortmembesar, true);

    for(i; i <= GetLastIdx(T); i++){
        if(Elmt(T, i) == Elmt(sortmengecil, i)){
            mengecil = true;
        }
        else if(Elmt(T, i) == Elmt(sortmembesar, i)){
            membesar = true;
        }
        else if(Elmt(T, i) == Elmt(sortmembesar, i) && Elmt(T,i) == Elmt(sortmengecil, i)){
            membesar = true;
            mengecil = true;
        }
        else{
            membesar = false;
            mengecil = false;
        }
    }

    if(mengecil){
        printf("Array monotonik tidak membesar\n");
    }
    else if(membesar){
        printf("Array monotonik tidak mengecil\n");
    }
    else if(membesar && mengecil){
        printf("Array monotonik statik\n");
    }
    else{
        printf("Array tidak monotonik\n");
    }
    return 0;
}
