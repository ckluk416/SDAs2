//dimodifikasi dari NRLL.c (cek ../quiz2/)

#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define info(P) (P)->info
#define next(P) (P)->next

// def tipedata yg disimpan di info
typedef struct {
    char nama[50];
    int nilaiUTS;
} infotype;

// def struct elemen list
typedef struct tElmtlist *address;
typedef struct tElmtlist {
    infotype info;         // info yg disimapn
    address next;          // pointer elemen berikutnya
} ElmtList;

// def struct linked list
typedef struct {
    address First; // pointer ke elemen pertama
} ListMahasiswa;


void CreateList(ListMahasiswa *L); // membuat list kosong; kreator/konstruktor
void DeallocateList(ListMahasiswa *L); // membebaskan memori yang dialokasikan; destruktor
int IsEmpty(ListMahasiswa L); // memeriksa apakah list kosong; validator
void InsertSorted(ListMahasiswa *L, infotype X); // menyisipkan elemen secara terurut berdasarkan nama; setter
void PrintListAscending(ListMahasiswa L); // mmenampilkan isi list secara ascending berdasarkan nama; printObjek
void PrintListDescending(ListMahasiswa L); // menampilkan isi list secara descending berdasarkan nilai; printObjek
int CountElements(ListMahasiswa L); // menghitung jumlah elemen dalam list
void CopyElements(ListMahasiswa L1, ListMahasiswa *L2, int kkm); // menyalin elemen list1 ke list2 dgn ketentuan nilai > 70; setter
void RemoveDuplicates(ListMahasiswa *L); // menghapus elemen duplikat berdasarkan nama

#endif