#include <stdio.h>
#include "NRLL.h"

// Fungsi untuk mencetak isi linked list
void PrintList(NRLL L) {
    address current = L.First; // Mulai dari elemen pertama
    while (current != NULL) {
        printf("%d -> ", current->info); // Cetak nilai elemen
        current = current->next; // Pindah ke elemen berikutnya
    }
    printf("NULL\n"); // Men andakan akhir list
}

int main() {
    NRLL list; // Deklarasi linked list
    CreateList(&list); // Membuat list kosong

    // Menyisipkan elemen di akhir
    InsertAtLast(&list, 10);
    InsertAtLast(&list, 20);
    InsertAtLast(&list, 30);

    // Mencetak isi linked list
    printf("Isi linked list setelah penyisipan di akhir:\n");
    PrintList(list); // Output: 10 -> 20 -> 30 -> NULL


    printf("Nilai dari elemen yang berada dua posisi setelah First: %d\n", info(next(next(list.First)))); // Output: 30

    DeallocateList(&list);

    return 0; 
}