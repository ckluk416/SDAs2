#ifndef PERPUSTAKAAN_H
#define PERPUSTAKAAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "NRLL.h"

typedef struct bukuSingly {
    char judul[50];
    int stok;
    struct bukuSingly *next;
} bukuSingly;

typedef struct bukuDoubly {
    char judul[50];
    int stok;
    struct bukuDoubly *next;
    struct bukuDoubly *prev;
} bukuDoubly;

typedef struct {
    char judul[50];
    int stok;
} bukuArray;

extern NRLL priorityQueues[3];

void tambahBukuSingly(bukuSingly **head, char *judul, int stok);
void tampilkanBukuSingly(bukuSingly *head);
void hapusBukuSingly(bukuSingly **head, char *judul);

void tambahBukuDoubly(bukuDoubly **head, char *judul, int stok);
void tampilkanBukuDoubly(bukuDoubly *head);
void hapusBukuDoubly(bukuDoubly **head, char *judul);

void tambahBukuArray(bukuArray *arr, int *size, char *judul, int stok);
void tampilkanBukuArray(bukuArray *arr, int size);
void hapusBukuArray(bukuArray *arr, int *size, char *judul);

void initPriorityQueues();
void tambahPeminjam(char *nama, int prioritas, char *judulBuku);
void prosesPeminjaman(char *judulBuku);
void tampilkanAntrian();
void batalkanPeminjaman(char *nama, char *judulBuku);

#endif