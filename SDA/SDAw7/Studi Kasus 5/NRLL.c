#include "NRLL.h"

// Membuat list kosong
void CreateList(NRLL *L) {
    L->First = NULL; // Inisialisasi pointer First ke NULL
}

// -----------------------------------------------------------------------------------------
//                                         Insert
// -----------------------------------------------------------------------------------------                                        
// Menyisipkan elemen di awal
//void InsertAtFirst(NRLL *L, infotype X) {
//    address P = (address)malloc(sizeof(ElmtList)); // Alokasikan memori untuk elemen baru
//     P->info = X; // Set nilai informasi
//     P->next = L->First; // Set next untuk menunjuk ke elemen pertama
//     L->First = P; // Set First untuk menunjuk ke elemen baru
// }

// // Menyisipkan sebelum elemen tertentu
// void InsertBeforeBetween(NRLL *L, infotype X, infotype Y) {
//     if (L->First == NULL) return; // Jika list kosong, tidak ada yang bisa dihapus

//     address P = (address)malloc(sizeof(ElmtList)); // Alokasikan memori untuk elemen baru
//     P->info = X; // Set nilai informasi

//     if (L->First->info == Y) { // Jika Y adalah elemen pertama
//         P->next = L->First; // Set next untuk menunjuk ke elemen pertama
//         L->First = P; // Set First untuk menunjuk ke elemen baru
//         return;
//     }

//     address current = L->First;
//     while (current->next != NULL && current->next->info != Y) {
//         current = current->next; // Cari elemen sebelum Y
//     }

//     if (current->next == NULL) return; // Jika Y tidak ditemukan

//     P->next = current->next; // Set next untuk menunjuk ke Y
//     current->next = P; // Set next current untuk menunjuk ke P
// }

// // Menyisipkan di antara dua elemen
// void InsertBetween(NRLL *L, infotype X, infotype Y) {
//     InsertAfterBetween(L, X, Y); // Menggunakan fungsi InsertAfterBetween
// }

// // Menyisipkan setelah elemen tertentu
// void InsertAfterBetween(NRLL *L, infotype X, infotype Y) {
//     address P = (address)malloc(sizeof(ElmtList)); // Alokasikan memori untuk elemen baru
//     P->info = X; // Set nilai informasi

//     address current = L->First;
//     while (current != NULL && current->info != Y) {
//         current = current->next; // Cari elemen Y
//     }

//     if (current == NULL) return; // Jika Y tidak ditemukan

//     P->next = current->next; // Set next untuk menunjuk ke elemen setelah Y
//     current->next = P; // Set next current untuk menunjuk ke P
// }

// Menyisipkan elemen di akhir
void InsertAtLast(NRLL *L, infotype X) {
    address P = (address)malloc(sizeof(ElmtList)); // Alokasikan memori untuk elemen baru
    P->info = X; // Set nilai informasi
    P->next = NULL; // Set next ke NULL

    if (L->First == NULL) { // Jika list kosong
        L->First = P; // Set First untuk menunjuk ke elemen baru
    } else {
        address current = L->First;
        while (current->next != NULL) {
            current = current->next; // Cari elemen terakhir
        }
        current->next = P; // Set next elemen terakhir untuk menunjuk ke P
    }
}

// // Menyisipkan elemen dengan nilai tertentu
// void InsertValue(NRLL *L, infotype X) {
//     InsertAtLast(L, X); // Menggunakan fungsi InsertAtLast
// }


// -----------------------------------------------------------------------------------------
//                                         delete
// -----------------------------------------------------------------------------------------  
// Menghapus elemen di awal
// void DeleteAtFirst(NRLL *L) {
//     if (L->First == NULL) return; // Jika list kosong, tidak ada yang bisa dihapus

//     address temp = L->First; // Simpan elemen pertama
//     L->First = L->First->next; // Set First untuk menunjuk ke elemen kedua
//     free(temp); // Bebaskan memori elemen pertama
// }

// // Menghapus sebelum elemen tertentu
// void DeleteBeforeBetween(NRLL *L, infotype Y) {
//     if (L->First == NULL || L->First->info == Y) return; // Jika list kosong atau Y adalah elemen pertama

//     address current = L->First;
//     address previous = NULL;

//     while (current->next != NULL && current->next->info != Y) {
//         previous = current; // Simpan elemen sebelumnya
//         current = current->next; // Lanjutkan ke elemen berikutnya
//     }

//     if (current->next == NULL) return; // Jika Y tidak ditemukan

//     if (previous == NULL) { // Jika Y adalah elemen kedua
//         L->First = current->next; // Set First untuk menunjuk ke elemen ketiga
//     } else {
//         previous->next = current->next; // Set next previous untuk melewati elemen yang akan dihapus
//     }
//     free(current); // Bebaskan memori elemen yang dihapus
// }

// Menghapus elemen tertentu
void DeleteBetween(NRLL *L, infotype Y) {
    if (L->First == NULL) return; // Jika list kosong, tidak ada yang bisa dihapus

    address current = L->First;
    address previous = NULL;

    while (current != NULL && current->info != Y) {
        previous = current; // Simpan elemen sebelumnya
        current = current->next; // Lanjutkan ke elemen berikutnya
    }

    if (current == NULL) return; // Jika Y tidak ditemukan

    if (previous == NULL) { // Jika Y adalah elemen pertama
        L->First = current->next; // Set First untuk menunjuk ke elemen kedua
    } else {
        previous->next = current->next; // Set next previous untuk melewati elemen yang akan dihapus
    }
    free(current); // Bebaskan memori elemen yang dihapus
}

// // Menghapus setelah elemen tertentu
// void DeleteAfterBetween(NRLL *L, infotype Y) {
//     address current = L->First;

//     while (current != NULL && current->info != Y) {
//         current = current->next; // Cari elemen Y
//     }

//     if (current == NULL || current->next == NULL) return; // Jika Y tidak ditemukan atau Y adalah elemen terakhir

//     address temp = current->next; // Simpan elemen setelah Y
//     current->next = temp->next; // Set next current untuk melewati elemen yang akan dihapus
//     free(temp); // Bebaskan memori elemen yang dihapus
// }

// // Menghapus elemen di akhir
// void DeleteAtLast(NRLL *L) {
//     if (L->First == NULL) return; // Jika list kosong, tidak ada yang bisa dihapus

//     if (L->First->next == NULL) { // Jika hanya ada satu elemen
//         free(L->First); // Bebaskan memori elemen pertama
//         L->First = NULL; // Set First ke NULL
//         return;
//     }

//     address current = L->First;
//     while (current->next->next != NULL) {
//         current = current->next; // Cari elemen sebelum terakhir
//     }

//     free(current->next); // Bebaskan memori elemen terakhir
//     current->next = NULL; // Set next elemen sebelum terakhir ke NULL
// }

// // Menghapus elemen dengan nilai tertentu
// void DeleteValue(NRLL *L, infotype X) {
//     DeleteBetween(L, X); // Menggunakan fungsi DeleteBetween
// }



// // -----------------------------------------------------------------------------------------
// //                                         modify
// // -----------------------------------------------------------------------------------------  
// // Memodifikasi elemen di awal
// void ModifyAtFirst(NRLL *L, infotype X) {
//     if (L->First == NULL) return; // Jika list kosong, tidak ada yang bisa dimodifikasi

//     L->First->info = X; // Set nilai informasi elemen pertama
// }

// // Memodifikasi sebelum elemen tertentu
// void ModifyBeforeBetween(NRLL *L, infotype Y, infotype X) {
//     if (L->First == NULL || L->First->info == Y) return; // Jika list kosong atau Y adalah elemen pertama

//     address current = L->First;
//     address previous = NULL;

//     while (current->next != NULL && current->next->info != Y) {
//         previous = current; // Simpan elemen sebelumnya
//         current = current->next; // Lanjutkan ke elemen berikutnya
//     }

//     if (current->next == NULL) return; // Jika Y tidak ditemukan

//     if (previous != NULL) {
//         previous->next->info = X; // Set nilai informasi elemen sebelum Y
//     }
// }

// // Memodifikasi elemen tertentu
// void ModifyBetween(NRLL *L, infotype Y, infotype X) {
//     if (L->First == NULL) return; // Jika list kosong, tidak ada yang bisa dimodifikasi

//     address current = L->First;
//     while (current != NULL && current->info != Y) {
//         current = current->next; // Cari elemen Y
//     }

//     if (current != NULL) {
//         current->info = X; // Set nilai informasi elemen Y
//     }
// }

// // Memodifikasi elemen setelah elemen tertentu
// void ModifyAfterBetween(NRLL *L, infotype Y, infotype X) {
//     address current = L->First;

//     while (current != NULL && current->info != Y) {
//         current = current->next; // Cari elemen Y
//     }

//     if (current != NULL && current->next != NULL) {
//         current->next->info = X; // Set nilai informasi elemen setelah Y
//     }
// }

// // Memodifikasi elemen di akhir
// void ModifyAtLast(NRLL *L, infotype X) {
//     if (L->First == NULL) return; // Jika list kosong, tidak ada yang bisa dimodifikasi

//     address current = L->First;
//     while (current->next != NULL) {
//         current = current->next; // Cari elemen terakhir
//     }

//     current->info = X; // Set nilai informasi elemen terakhir
// }

// // Memodifikasi elemen dengan nilai tertentu
// void ModifyValue(NRLL *L, infotype X, infotype NewValue) {
//     address current = L->First;
//     while (current != NULL) {
//         if (current->info == X) {
//             current->info = NewValue; // Set nilai informasi elemen yang sesuai
//             return;
//         }
//         current = current->next; // Lanjutkan ke elemen berikutnya
//     }
// }


// Fungsi untuk membebaskan memori yang dialokasikan untuk linked list
void DeallocateList(NRLL *L) {
    address current = L->First; // Mulai dari elemen pertama
    address temp;
    while (current != NULL) {
        temp = current; // Simpan elemen saat ini
        current = current->next; // Pindah ke elemen berikutnya
        free(temp); // Bebaskan memori elemen yang disimpan
    }
    L->First = NULL; // Set First ke NULL setelah semua elemen dibebaskan
}