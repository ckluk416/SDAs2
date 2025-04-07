#include "SLL.h"

// mmbuat kota dan list kosong
void CreateCity(City *city, char *name) {
    strcpy(city->cityName, name);
    CreateList(&(city->list));
}

// mnambahkan orang ke kota
void AddPersonToCity(City *city, char *personName) {
    InsertAtLast(&(city->list), personName);
}

// hapus orang dari kota
void DeletePersonFromCity(City *city, char *personName) {
    DeleteBetween(&(city->list), personName);
}

// mnampilkan isi kota
void DisplayCity(City *city) {
    printf("Kota: %s\n", city->cityName);
    address current = city->list.First;
    while (current != NULL) {
        printf("  Nama: %s\n", current->info);
        current = current->next;
    }
}

// dealloc kota
void DeallocateAllCities(City cities[], int size) {
    for (int i = 0; i < size; i++) {
        DeallocateList(&(cities[i].list));
    }
}