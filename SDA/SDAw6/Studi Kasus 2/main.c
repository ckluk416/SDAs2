#include "dectobin.h"
#include <stdio.h>

int main(){
    int n;

    printf("masukkan bil desimal: ");
    scanf("%d", &n);
    
    DecToBin(n);

    return 0;
}