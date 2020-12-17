/*
Richard Rivaldo
13519185
Praktikum 1
Membuat file yang mencari nilai maksimum dari 3 bilangan
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);
    int c;
    scanf("%d", &c);

    if ((a >= b) && (a >= c)){
        printf("%d", a);
    }
    else if ((b >= a) && (b >= c)){
        printf("%d", b);
    }
    else{
        printf("%d", c);
    }
    return 0;
}

