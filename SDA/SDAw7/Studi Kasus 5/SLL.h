#ifndef SLL_H
#define SLL_H

#include "NRLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struktur data untuk kota dan linked list
typedef struct City {
    char cityName[50];
    NRLL list;
} City;

// proc untuk membuat kota
void CreateCity(City *city, char *name);

// proc untuk menambah orang ke kota
void AddPersonToCity(City *city, char *personName);

// proc untuk menghapus orang dari kota
void DeletePersonFromCity(City *city, char *personName);

// proc untuk menampilkan isi kota
void DisplayCity(City *city);

//proc dealloc kota
void DeallocateAllCities(City cities[], int size);

#endif