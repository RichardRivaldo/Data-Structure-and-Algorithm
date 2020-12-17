/* Richard Rivaldo - 13519185
Praktikum 8 - Stack */

#include "stackt.h"
#include "mesintoken.h"
#include <stdio.h>
#include <math.h>

int main(){
    Stack S;
    int operan1, operan2, hasil, result;

    CreateEmpty(&S);

    STARTTOKEN();

    while(!EndToken){
        if(CToken.tkn == 'b'){
            printf("%d\n", CToken.val);
            Push(&S, CToken.val);
        }
        else{
            Pop(&S, &operan2);
            Pop(&S, &operan1);
            if(CToken.tkn == '+'){
                hasil = operan1 + operan2;
            }
            else if(CToken.tkn == '-'){
                hasil = operan1 - operan2;
            }
            else if(CToken.tkn == '*'){
                hasil = operan1 * operan2;
            }
            else if(CToken.tkn == '/'){
                hasil = operan1 / operan2;
            }
            else if(CToken.tkn == '^'){
                hasil = pow(operan1, operan2);
            }
            printf("%d %c %d\n", operan1, CToken.tkn, operan2);
            printf("%d\n", hasil);
            Push(&S, hasil);
        }
        ADVTOKEN();
    }
    if(IsEmpty(S)){
        printf("Ekspresi kosong\n");
    }
    else{
        Pop(&S, &result);
        printf("Hasil=%d\n", result);
    }

    return 0;
}
