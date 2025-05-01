#include "perpustakaan.h"

int main() {
    initPriorityQueues();
    
    bukuSingly *singlyBooks = NULL;
    bukuDoubly *doublyBooks = NULL;
    bukuArray arrayBooks[10];
    int arraySize = 0;
    
    // Scenario a
    printf("=== Skenario A: Tambah Buku ===\n");
    tambahBukuSingly(&singlyBooks, "Buku1", 1);
    tambahBukuSingly(&singlyBooks, "Buku2", 1);
    tambahBukuDoubly(&doublyBooks, "Buku1", 1);
    tambahBukuDoubly(&doublyBooks, "Buku2", 1);
    tambahBukuArray(arrayBooks, &arraySize, "Buku1", 1);
    tambahBukuArray(arrayBooks, &arraySize, "Buku2", 1);
    
    printf("\nBuku dalam Singly Linked List:\n");
    tampilkanBukuSingly(singlyBooks);
    printf("\nBuku dalam Doubly Linked List:\n");
    tampilkanBukuDoubly(doublyBooks);
    printf("\nBuku dalam Array:\n");
    tampilkanBukuArray(arrayBooks, arraySize);
    
    // Scenario b-e
    printf("\n=== Skenario B-E: Tambah Peminjam ===\n");
    tambahPeminjam("Anggota1", 1, "Buku1"); // Mahasiswa
    tambahPeminjam("Dosen1", 0, "Buku1");   // Dosen
    tambahPeminjam("Umum1", 2, "Buku1");    // Umum
    tambahPeminjam("Umum1", 2, "Buku2");    // Umum    
    printf("\nAntrian peminjaman:\n");
    tampilkanAntrian();
    
    // Scenario f
    printf("\n=== Skenario F: Proses Peminjaman ===\n");
    printf("Memproses peminjaman Buku1:\n");
    prosesPeminjaman("Buku1");   
    printf("\nAntrian setelah peminjaman:\n");
    tampilkanAntrian();
    
    // Scenario g
    printf("\n=== Skenario G: Proses Pengembalian ===\n");
    printf("Buku1 dikembalikan, memproses antrian berikutnya:\n");
    prosesPeminjaman("Buku1");    
    printf("\nAntrian setelah peminjaman:\n");
    tampilkanAntrian();
    
    // Scenario h
    printf("\n=== Skenario H: Pembatalan Peminjaman ===\n");
    printf("Umum1 membatalkan peminjaman Buku2:\n");
    batalkanPeminjaman("Umum1", "Buku2");    
    printf("\nAntrian setelah pembatalan:\n");
    tampilkanAntrian();
    
    for (int i = 0; i < 3; i++) {
        DeallocateList(&priorityQueues[i]);
    }
    bukuSingly *temp;
    while (singlyBooks != NULL) {
        temp = singlyBooks;
        singlyBooks = singlyBooks->next;
        free(temp);
    }
    bukuDoubly *tempD;
    while (doublyBooks != NULL) {
        tempD = doublyBooks;
        doublyBooks = doublyBooks->next;
        free(tempD);
    }    
    return 0;
}