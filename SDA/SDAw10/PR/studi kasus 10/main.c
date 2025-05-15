#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nbtrees.h"
#include "converter.h"

#define MAX_INPUT 100

void toUpperCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    Isi_Tree tree;
    BuildTreeFromData(tree);
    
    int choice;
    char input[MAX_INPUT];
    char output[MAX_INPUT * 5];
    
    printf("=== Konverter Karakter-Kode ===\n");
    
    do {
        printf("\nMenu Konversi:\n");
        printf("1. String ke Kode\n");
        printf("2. Kode ke String\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                printf("Masukkan string (huruf/angka/spasi): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = '\0';
                
                StringToCode(tree, input, output);
                printf("Kode untuk '%s': %s\n", input, output);
                break;
                
            case 2:
                printf("Masukkan kode (conth: LR LL RRR): ");
                fgets(input, MAX_INPUT, stdin);
                input[strcspn(input, "\n")] = '\0';
                
                CodeToString(tree, input, output);
                printf("String untuk kode '%s': %s\n", input, output);
                break;
                
            case 3:
                printf("Keluar dari program.\n");
                break;
                
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 3);
    
    return 0;
}