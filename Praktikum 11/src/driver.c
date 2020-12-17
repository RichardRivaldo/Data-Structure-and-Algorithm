#include "listrek.c"

List IsiListI(List L) {
  L = Alokasi(1);
  int i = 2;
  while (i < 4){
    L = KonsB(L, i);
    i++;
  }
  return L;
}

int main(){
    List L = IsiListI(L);
    if(FirstElmt(L) == 1){
        printf("True");
    }
}
