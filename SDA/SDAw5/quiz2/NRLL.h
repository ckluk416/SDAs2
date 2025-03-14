#ifndef NRLL_H
#define NRLL_H

#include <stdlib.h>
#include <stdio.h>

// Makro untuk akses komponen
#define info(P) (P)->info
#define next(P) (P)->next

// Definisi tipe data untuk informasi yang disimpan dalam list
typedef int infotype;

// Definisi struktur untuk elemen list
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;         // Informasi yang disimpan dalam elemen
    address next;          // Pointer ke elemen berikutnya
} ElmtList;

// Definisi struktur untuk linked list
typedef struct {
    address First; // Pointer ke elemen pertama
} NRLL;

void CreateList(NRLL *L); // Membuat list kosong

// prosedur2 insert
void InsertAtFirst(NRLL *L, infotype X); // Menyisipkan elemen di awal
//void InsertBeforeBetween(NRLL *L, infotype X, infotype Y); // Menyisipkan sebelum elemen tertentu
//void InsertBetween(NRLL *L, infotype X, infotype Y); // Menyisipkan di antara dua elemen
void InsertAfterBetween(NRLL *L, infotype X, infotype Y); // Menyisipkan setelah elemen tertentu
void InsertAtLast(NRLL *L, infotype X); // Menyisipkan elemen di akhir
//void InsertValue(NRLL *L, infotype X); // Menyisipkan elemen dengan nilai tertentu

// prosedur2 delete
void DeleteAtFirst(NRLL *L); // Menghapus elemen di awal
//void DeleteBeforeBetween(NRLL *L, infotype Y); // Menghapus sebelum elemen tertentu
void DeleteBetween(NRLL *L, infotype Y); // Menghapus elemen tertentu
//void DeleteAfterBetween(NRLL *L, infotype Y); // Menghapus setelah elemen tertentu
void DeleteAtLast(NRLL *L); // Menghapus elemen di akhir
//void DeleteValue(NRLL *L, infotype X); // Menghapus elemen dengan nilai tertentu

//// prosedur2 modify
//void ModifyAtFirst(NRLL *L, infotype X); // Memodifikasi elemen di awal
//void ModifyBeforeBetween(NRLL *L, infotype Y, infotype X); // Memodifikasi sebelum elemen tertentu
//void ModifyBetween(NRLL *L, infotype Y, infotype X); // Memodifikasi elemen tertentu
//void ModifyAfterBetween(NRLL *L, infotype Y, infotype X); // Memodifikasi setelah elemen tertentu
//void ModifyAtLast(NRLL *L, infotype X); // Memodifikasi elemen di akhir
//void ModifyValue(NRLL *L, infotype X, infotype NewValue); // Memodifikasi elemen dengan nilai tertentu

// Fungsi untuk membebaskan memori yang dialokasikan untuk linked list
void DeallocateList(NRLL *L); //deallocate

#endif // NRLL_H