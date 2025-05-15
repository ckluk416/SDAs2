#ifndef NBTREES_H
#define NBTREES_H
#include <stdio.h>
#include <stdbool.h>
#define JML_MAKS 20
#define KEBAWAH 1
#define KEATAS 2
#define KEKANAN 3
#define NIL 0

typedef char infotype;
typedef int address;

typedef struct {
    infotype info;
    address ps_fs, ps_nb, ps_pr;
} nbtree;

typedef nbtree Isi_Tree[JML_MAKS + 1];

void CreateTree(Isi_Tree X, int Jml_Node);
    // Create Non Binary Tree sebanyak Jml_Node
    // Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
    // Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input
bool IsEmpty(Isi_Tree P);
    // Mengirimkan true jika Isi_Tree KOSONG

void PreOrder(Isi_Tree P, address idx);
// void PreOrderNonRekursif(Isi_Tree P, int Jml_Node);
    /* Traversal PreOrder */
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */
void InOrder(Isi_Tree P, address idx);
// void InOrderNonRekursif(Isi_Tree P, int Jml_Node);
    /* Traversal InOrder */
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */
void PostOrder(Isi_Tree P, address idx);
// void PostOrderNonRekursif(Isi_Tree P, int Jml_Node);
    /* Traversal PostOrder */
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb, Parent */
void LevelOrder(Isi_Tree P, int Jml_Node);
// void LevelOrderNonRekursif(Isi_Tree P, int Jml_Node);
    /* Traversal LevelOrder */
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditampilkan secara Level Order */

void PrintTree(Isi_Tree P, int Jml_Node);
    /* IS : P terdefinisi */
    /* FS : Semua simpul P sudah ditulis ke layar */
bool Search(Isi_Tree P, infotype X, int Jml_Node);
    /* Mengirimkan true jika ada node dari P yang bernilai X */
int nbElmt(Isi_Tree P, int Jml_Node);
    /* Mengirimkan banyak elemen (node) di pohon non biner P */
int nbDaun(Isi_Tree P, int Jml_Node);
    /* Mengirimkan banyak daun (node) pohon non biner P */
int Level(Isi_Tree P, infotype X, int Jml_Node);
    /* Mengirimkan level dari node X yang merupakan salah satu simpul dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */
int Depth(Isi_Tree P, address idx);
    /* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
    /* Basis : Pohon Kosong, tingginya Nol */
int Max(int Data1, int Data2);
    /* Mengirimkan Nilai terbesar dari dua data */
#endif