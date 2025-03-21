#include "dectobin.h"
#include <stdio.h>

void DecToBin(int n){
    Stack S;
    CreateStack(&S);

    while (n > 0){
        Push(&S, n % 2);
        n /= 2;
    }

    printf("bilangan biner: ");
    while (!isEmpty(S)){
        printf("%d", Top(S));
        Pop(&S);
    }

    DeallocateStack(&S);
}