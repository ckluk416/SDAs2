// gambar pola bintang berbentuk layang layang
//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int i = 0;
    while (i < n){
        int j = 0;
        while (j < n){
            if (j < n - i - 1) printf(" ");
            else printf("*");
            j++;
        }
        j = 0;
        while (j < n){
            if (j < i) printf("*");
            j++;
        }
        printf("\n");
        i++;
    }
    i = 0;
    while (i < n - 1){
        int j = 0;
        while (j < n){
            if (j <= i) printf(" ");
            else printf("*");
            j++;
        }
        j = 0;
        while (j < n){
            if (j < n - i - 1) printf("*");
            j++;
        }
        printf("\n");
        i++;
    }
}