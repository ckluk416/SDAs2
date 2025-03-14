#include <stdio.h>
#include "NRLL.h"

void PrintList(NRLL L) {
    printf("elemen list= ");
    address current = L.First;
     while (current != NULL) {    
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

int main(){
    NRLL list;
    CreateList(&list);

    // 1. masukan bilangan 7 sebagai elemen pertama 
    InsertAtFirst(&list, 7);
    PrintList(list);
    // 2. masukan bilangan 11 sebagai elemen kedua 
    InsertAtLast(&list, 11);
    PrintList(list);
    // 3. masukan bilangan 9 diantara bilangan 7 dan 11 
    InsertAfterBetween(&list, 9, 7);
    PrintList(list);
    // 4. masukan bilangan 5 di awal list 
    InsertAtFirst(&list, 5);
    PrintList(list);
    // 5. masukkan bilangan 13 di akhir list
    InsertAtLast(&list, 13);
    PrintList(list);
    // 6. hapus elemen terakhir (13) dari list
    DeleteAtLast(&list);
    PrintList(list);
    // 7. hapus bilangan 7 pada list
    DeleteBetween(&list, 7);
    PrintList(list);
    // 8. hapus elemen pertama (5) dari list
    DeleteAtFirst(&list);
    PrintList(list);
    // 9. hapus semua elemen list
    DeallocateList(&list);
    PrintList(list);
}