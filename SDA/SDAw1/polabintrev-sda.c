#include <stdio.h>

int main(){
    int n = 5;
   // int n;
    //scanf("%d", &n);

    int i = 0;
    while (i < n){
        int j = 0;
        while (j < n){
            if (j < n-i-1) printf("  ");
            else printf("* ");
            j++;
        }
        printf("\n");
        i++;
    }

}